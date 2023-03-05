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
  int N,X,Y;
  cin >> N >> X >> Y;
  vector<vector<ll>> dp(N+5, vector<ll>(2, 0));
  dp[0][0] = 1;
  rep(i,N-1) {
    dp[i][1] += dp[i][0] * X;
    dp[i+1][0] += dp[i][0];
    dp[i+1][0] += dp[i][1];
    dp[i+1][1] = dp[i][1] * Y;
  }
  print(dp[N-1][1]);
  return 0;
}
