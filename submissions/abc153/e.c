#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
#include <limits.h>
//#include <math.h>

int main() {
  int h, n;
  scanf("%d%d", &h, &n);
  int a[n], b[n];
  for (int i=0; i<n; i++) scanf("%d%d", a+i, b+i);
  int dp[h+1];
  for (int i=0; i<h+1; i++) {
    dp[i] = INT_MAX;
  }
  for (int i=0; i<n; i++) {
    for (int j=0; j<h+1; j++) {
      if (j-a[i] <= 0) {
        if (dp[j] < b[i]) {
          continue;
        } else {
          dp[j] = b[i];
        }
      }
      else if (dp[j] < dp[j-a[i]]+b[i]) {
        continue;
      } else {
        dp[j] = dp[j-a[i]]+b[i];
      }
    }
  }
  printf("%d\n", dp[h]);
  return 0;
}
