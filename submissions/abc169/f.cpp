#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
ll dp[3005][3005];

int main() {
  int N, S;
  cin >> N >> S;
  int A[N];
  for (int i=0; i<N; i++)
    cin >> A[i];
  dp[0][0] = 1;
  for (int i=0; i<N; i++) {
    int a = A[i];
    for (int j=0; j<=S; j++) {
      dp[i+1][j] += 2 * dp[i][j];
      dp[i+1][j] %= MOD;
      if (j+a <= S) {
        dp[i+1][j+a] += dp[i][j];
        dp[i+1][j+a] %= MOD;
      }
    }
  }
  cout << dp[N][S] << endl;
  return 0;
}
