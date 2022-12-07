#include <bits/stdc++.h>
using namespace std;
#define INF 100000

int main() {
  int N, Ma, Mb;
  cin >> N >> Ma >> Mb;
  int a[N], b[N], c[N], dp[401][401], ans = INF;
  for (int i=0; i<N; i++)
    cin >> a[i] >> b[i] >> c[i];
  for (int j=0; j<=400; j++)
    for (int k=0; k<=400; k++)
      dp[j][k] = INF;
  dp[0][0] = 0;
  for (int i=0; i<N; i++) {
    int ai = a[i], bi = b[i], ci = c[i];
    for (int j=400; j>=ai; j--) {
      for (int k=400; k>=bi; k--) {
        dp[j][k] = min(dp[j][k], dp[j-ai][k-bi]+ci);
      }
    }
  }
  for (int i=1; i*Ma<=400 && i*Mb<=400; i++)
    ans = min(ans, dp[i*Ma][i*Mb]);
  if (ans == INF)
    ans = -1;
  cout << ans << endl;
  return 0;
}
