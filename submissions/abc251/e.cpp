#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
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
  const ll M = 1e18;
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  vector<vector<ll>> dp(N, vector<ll>(4, M));
  dp[0][0] = A[N-1];
  dp[0][3] = 0;
  rep(i,N-1) {
    rep(j,2) {
      dp[i+1][j*2] = min(dp[i][j*2], dp[i][j*2+1]) + A[i];
      dp[i+1][j*2+1] = dp[i][j*2];
    }
  }
  print(min(min(dp[N-1][0],dp[N-1][1]), dp[N-1][2]));
  return 0;
}
