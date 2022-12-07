#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


int main() {
  int W, N, K;
  cin >> W >> N >> K;
  int A[N], B[N];
  rep(i, N) {
    cin >> A[i] >> B[i];
  }
  int dp[N+1][W+1][K+1];
  rep(i, W+1) {
    rep(j, K+1) {
      dp[0][i][j] = 0;
    }
  }
  rep(i, N) {
    rep(j, W+1) {
      rep(k, K+1) {
        dp[i+1][j][k] = dp[i][j][k];
        if (j>=A[i] && k>0)
          dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j-A[i]][k-1] + B[i]);
      }
    }
  }
  int ans = 0;
  rep(i, W+1) {
    rep(j, K+1) {
      ans = max(ans, dp[N][i][j]);
    }
  }
  print(ans);
  return 0;
}
