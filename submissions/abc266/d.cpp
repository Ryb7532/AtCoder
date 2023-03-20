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
  int N;
  cin >> N;
  vector<int> T(N), X(N);
  vector<ll> A(N);
  rep(i,N) {
    cin >> T[i] >> X[i] >> A[i];
  }
  vector<vector<ll>> dp(1e5+1, vector<ll>(5, -1e15));
  dp[0][0] = 0;
  int i = 0;
  for (int t=1; t<=1e5; t++) {
    rep(j,5) {
      dp[t][j] = dp[t-1][j];
      if (j > 0)
        dp[t][j] = max(dp[t][j], dp[t-1][j-1]);
      if (j < 4)
        dp[t][j] = max(dp[t][j], dp[t-1][j+1]);
    }
    if (i < N && T[i] == t) {
      dp[t][X[i]] += A[i];
      i++;
    }
  }
  ll res = 0;
  rep(j,5) {
    res = max(res, dp[1e5][j]);
  }
  print(res);
  return 0;
}
