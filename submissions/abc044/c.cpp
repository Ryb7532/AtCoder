#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, A;
  cin >> N >> A;
  int x[N];
  ll dp[N+1][2501], ans = 0;
  for (int i=0; i<N; i++)
    cin >> x[i];
  for (int i=0; i<=N; i++)
    for (int j=0; j<=2500; j++)
      dp[i][j] = 0;
  dp[0][0] = 1;
  for (int i=0; i<N; i++) {
    for (int k=N; k>0; k--)
      for (int j=2500; j>=x[i]; j--) {
        dp[k][j] += dp[k-1][j-x[i]];
    }
  }
  for (int i=1; i<=N; i++)
    ans += dp[i][i*A];
  cout << ans << endl;
  return 0;
}