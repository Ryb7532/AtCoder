#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl

int main() {
  int N;
  cin >> N;
  vector<ll> X(N), Y(N), Z(N);
  ll sum = 0;
  rep(i,N) {
    cin >> X[i] >> Y[i] >> Z[i];
    sum += Z[i];
  }
  vector<ll> dp(1e5+5, 1e18);
  dp[0] = 0;
  rep(i,N) {
    int x = X[i], y = Y[i], z = Z[i];
    rrep(j,1e5+5, z) {
      if (x > y) {
        dp[j] = dp[j-z];
      } else {
        dp[j] = min(dp[j], dp[j-z]+(y-x+1)/2);
      }
    }
  }
  ll res = 1e18;
  rep(i,(sum+1)/2,1e5+5) {
    res = min(res, dp[i]);
  }
  print(res);
  return 0;
}