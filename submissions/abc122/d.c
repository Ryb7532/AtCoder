#include <stdio.h>

#define MOD 1000000007;

int main() {
  int n;
  scanf("%d", &n);
  long dp[101][64];
  for (int i=0; i<101; i++) for (int j=0; j<64; j++) dp[i][j] = 0;
  for (int i=0; i<16; i++) dp[2][63-i] = 1;
  for (int i=3; i<n+1; i++) {
    for (int j=0; j<64; j++) {
      if (j == 6) continue;
      if (j == 18) continue;
      if (j == 9) continue;
      if (j%16 == 6) {
        for (int idx=1; idx<4; idx++) {
          dp[i][j] += dp[i-1][idx*16+j/4];
          dp[i][j] %= MOD;
        }
      }
      else if (j/16 == 1 && j%4 == 2) {
        for (int idx=1; idx<4; idx++) {
          dp[i][j] += dp[i-1][idx*16+j/4];
          dp[i][j] %= MOD;
        }
      }
      else {
        for (int idx=0; idx<4; idx++) {
          dp[i][j] += dp[i-1][idx*16+j/4];
          dp[i][j] %= MOD;
        }
      }
    }
  }
  long ans = 0;
  for (int i=0; i<64; i++) {
    ans += dp[n][i];
    ans %= MOD;
  }
  printf("%ld\n", ans);
  return 0;
}
