#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define Max(a, b) ((a > b) ? a : b)

int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  int a[n], b[n];
  for (int i=0; i<n; i++)
    scanf("%d%d", a+i, b+i);
  int dp1[n][t], dp2[n][t];
  for (int i=0; i<t; i++) {
    dp1[0][i] = 0;
    dp2[n-1][i] = 0;
  }
  for (int i=0; i<n; i++) {
    dp1[i][0] = 0;
    dp2[i][0] = 0;
  }
  for (int i=1; i<n; i++) {
    for (int j=1; j<t; j++) {
      if (j < a[i-1])
        dp1[i][j] = dp1[i-1][j];
      else
        dp1[i][j] = Max(dp1[i-1][j], dp1[i-1][j-a[i-1]] + b[i-1]);
      if (j < a[n-i])
        dp2[n-i-1][j] = dp2[n-i][j];
      else
        dp2[n-i-1][j] = Max(dp2[n-i][j], dp2[n-i][j-a[n-i]] + b[n-i]);
    }
  }
  int ans = 0;
  for (int i=0; i<n; i++)
    for (int j=0; j<t; j++)
      ans = Max(ans, dp1[i][j]+dp2[i][t-1-j]+b[i]);
  printf("%d\n", ans);
  return 0;
}
