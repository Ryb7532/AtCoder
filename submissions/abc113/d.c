#include <stdio.h>

#define MOD 1000000007

int main() {
  int h, w, k;
  scanf("%d%d%d", &h, &w, &k);
  int dp[h+1][w];
  for (int i=0; i<h+1; i++) {
    for (int j=0; j<w; j++) {
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;
  for (int i=1; i<h+1; i++) {
    for (int k=0; k<(1<<(w-1)); k++) {
      int check = 1;
      for (int l=0; l<w-2; l++) {
        if (((k>>l)&3) == 3) {
          check = 0;
          break;
        }
      }
      if (check == 0) continue;
      for (int j=0; j<w; j++) {
        if (j<w-1 && ((k>>j)&1) == 1) {
          dp[i][j+1] += dp[i-1][j];
          dp[i][j+1] %= MOD;
        }else if (j>0 && ((k>>(j-1))&1) == 1) {
          dp[i][j-1] += dp[i-1][j];
          dp[i][j-1] %= MOD;
        }else {
          dp[i][j] += dp[i-1][j];
          dp[i][j] %= MOD;
        }
      }
    }
  }
  printf("%d\n", dp[h][k-1]);
  return 0;
}
