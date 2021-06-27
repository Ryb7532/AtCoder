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
  string S;
  int n;
  cin >> S;
  n = S.size();
  vec<bool> c(n);
  rep(i,n) {
    c[i] = (S[i]=='o');
  }
  int ans = 10;
  reps(i,(1<<(n-1)),(1<<n)) {
    int cnt=0;
    vec<bool> w(n,false);
    bool can = true;
    rep(j,n) {
      if ((1<<j)&i) {
        cnt++;
        rep(k,n) {
          w[k] = w[k]||c[(j+k)%n];
        }
      }
    }
    rep(j,n) {
      can = can && w[j];
    }
    if (can)
      ans = min(ans,cnt);
  }
  print(ans);
  return 0;
}
