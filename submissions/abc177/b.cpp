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
  string S,T;
  cin >> S >> T;
  int ans = 1e9,N = S.size(),tsize = T.size();
  rep(i,N) {
    if (i+tsize>N)
      continue;
    int cnt = 0;
    rep(j,tsize) {
      if (S[i+j] != T[j])
        cnt++;
    }
    ans = min(ans,cnt);
  }
  print(ans);
  return 0;
}
