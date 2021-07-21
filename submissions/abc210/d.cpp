#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"

const ll INF = 1LL<<50;

int main() {
  int H,W;
  ll C;
  cin >> H >> W >> C;
  vec<vec<ll>> A(H,vec<ll>(W));
  rep(i,H) {
    rep(j,W) {
      cin >> A[i][j];
    }
  }
  ll res = INF;
  vec<vec<ll>> dp(H+1,vec<ll>(W+1,INF));
  rep(i,H) {
    rep(j,W) {
      dp[i+1][j+1] = min(dp[i][j+1],dp[i+1][j])+C;
      res = min(res,dp[i+1][j+1]+A[i][j]);
      dp[i+1][j+1] = min(dp[i+1][j+1],A[i][j]);
    }
  }
  rep(i,H) {
    rep(j,W) {
      dp[i+1][j+1] = min(dp[i][j+1],dp[i+1][j])+C;
      res = min(res,dp[i+1][j+1]+A[H-i-1][j]);
      dp[i+1][j+1] = min(dp[i+1][j+1],A[H-i-1][j]);
    }
  }
  print(res);
  return 0;
}
