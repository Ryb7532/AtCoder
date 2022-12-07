#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

#define MIN(a, b) ((a<b) ? a : b)
#define N 100000

int main() {
  int n;
  scanf("%d", &n);
  int dp[n+1];
  dp[0] = 0;
  for (int i=1; i<n+1; i++) {
    dp[i] = 100001;
    for (int j=9; j<=i; j*=9) {
      for (int k=1; k<=i/j && k<9; k++) {
        dp[i] = MIN(dp[i], dp[i-k*j]+k);
      }
    }
    for (int j=6; j<=i; j*=6) {
      for (int k=1; k<=i/j && k<6; k++) {
        dp[i] = MIN(dp[i], dp[i-k*j]+k);
      }
    }
    for (int j=1; j<6 && j<=i; j++) dp[i] = MIN(dp[i], dp[i-j]+j);
  }
  printf("%d\n", dp[n]);
  return 0;
}
