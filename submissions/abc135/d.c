#include <stdio.h>
#include <string.h>

#define MOD 1000000007;

int main() {
  char s[100005];
  gets(s);
  int len = strlen(s), a;
  int dp[len+2][13];
  dp[0][0] = 1;
  for (size_t i = 1; i < 13; i++) {
    dp[0][i] = 0;
  }
  for (size_t i = 0; i < len; i++) {
    for (size_t j = 0; j < 13; j++) {
      dp[i+1][j] = 0;
    }
    a = (s[i] == '?') ? -1 : s[i] - '0';
    for (size_t j = 0; j < 13; j++) {
      if (a == -1) {
        for (size_t k = 0; k < 10; k++) {
          dp[i+1][(j*10+k)%13] += dp[i][j];
          dp[i+1][(j*10+k)%13] %= MOD;
        }
      }else {
        dp[i+1][(j*10+a)%13] += dp[i][j];
        dp[i+1][(j*10+a)%13] %= MOD;
      }
    }
  }
  printf("%d\n", dp[len][5]);
  return 0;
}
