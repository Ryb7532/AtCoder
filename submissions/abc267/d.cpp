#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N,M;
  cin >> N >> M;
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  vector<vector<ll>> dp(N+1, vector<ll>(M+1, -1e18));
  dp[0][0] = 0;
  rep(i,N) {
    rep(j,M) {
      dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
      dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + (j+1) * A[i]);
    }
    dp[i+1][M] = max(dp[i+1][M], dp[i][M]);
  }
  print(dp[N][M]);
  return 0;
}
