#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXD = 160*80+1;
bool dp[80][80][MAXD];

int main() {
  int H, W;
  cin >> H >> W;
  int A[H][W], B, ans = 0;
  for (int i=0; i<H; i++)
    for (int j=0; j<W; j++)
      cin >> A[i][j];
  for (int i=0; i<H; i++)
    for (int j=0; j<W; j++) {
      cin >> B;
      A[i][j] = abs(A[i][j]-B);
    }

  dp[0][0][A[0][0]] = true;

  for (int i=1; i<H; i++) {
    int d = A[i][0];
    for (int j=0; j<MAXD; j++) {
      if (!dp[i-1][0][j])
        continue;
      dp[i][0][j+d] = true;
      dp[i][0][abs(j-d)] = true;
    }
  }
  for (int i=1; i<W; i++) {
    int d = A[0][i];
    for (int j=0; j<MAXD; j++) {
      if (!dp[0][i-1][j])
        continue;
      dp[0][i][j+d] = true;
      dp[0][i][abs(j-d)] = true;
    }
  }
  for (int i=1; i<H; i++)
    for (int j=1; j<W; j++) {
    int d = A[i][j];
      for (int k=0; k<MAXD-d; k++) {
        if (!(dp[i-1][j][k] || dp[i][j-1][k]))
          continue;
        dp[i][j][k+d] = true;
        dp[i][j][abs(k-d)] = true;
      }
    }

  while (!dp[H-1][W-1][ans])
    ans++;
  cout << ans << endl;
  return 0;
}
