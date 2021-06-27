#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define max(a, b) (a > b ? a : b)

int main() {
  int n;
  scanf("%d", &n);
  int a[2][n];
  for (int i=0; i<2; i++)
    for (int j=0; j<n; j++)
      scanf("%d", &(a[i][j]));
  int sum[2][n], ans = 0;
  sum[0][0] = a[0][0];
  sum[1][n-1] = a[1][n-1];
  for (int i=1; i<n; i++) {
    sum[0][i] = sum[0][i-1] + a[0][i];
    sum[1][n-i-1] = sum[1][n-i] + a[1][n-i-1];
  }
  for (int i=0; i<n; i++)
    ans = max(ans, sum[0][i] + sum[1][i]);
  printf("%d\n", ans);
  return 0;
}
