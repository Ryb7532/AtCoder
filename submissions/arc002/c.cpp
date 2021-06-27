#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << a << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


int main() {
  int N;
  string S;
  cin >> N >> S;
  vec<int> c(N);
  int ans = N;
  rep(i,N) {
    switch (S[i]) {
    case 'A':
      c[i] = 0;
      break;
    case 'B':
      c[i] = 1;
      break;
    case 'X':
      c[i] = 2;
      break;
    case 'Y':
      c[i] = 3;
      break;
    }
  }
  rep(i,256) {
    int L[2],R[2],tmp = i,cnt = 0;
    vec<int> cc = c;
    rep(j,2) {
      L[j] = tmp%4;
      tmp >>= 2;
    }
    rep(j,2) {
      R[j] = tmp%4;
      tmp >>= 2;
    }
    rep1(j,N-1) {
      if (cc[j-1] == L[0] && cc[j] == L[1]) {
        cc[j-1] = -1;
        cc[j] = -1;
      }
    }
    rep1(j,N-1) {
      if (cc[j-1] == R[0] && cc[j] == R[1]) {
        cc[j-1] = -1;
        cc[j] = -1;
      }
    }
    rep(j,N) {
      if (cc[j] != -1)
        cnt++;
    }
    ans = min(ans,cnt+(N-cnt)/2);
  }
  print(ans);
  return 0;
}
