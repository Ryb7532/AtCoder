#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define Max(a, b) (a > b ? a : b)

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  double p[n];
  for (int i = 0; i < n; i++)
    scanf("%lf", p + i);
  double sumk[n - k + 1];
  sumk[0] = 0;
  for (int i = 0; i < k; i++)
  {
    sumk[0] += p[i];
  }
  for (int i = 1; i < n - k + 1; i++)
  {
    sumk[i] = sumk[i - 1] - p[i - 1] + p[i + k - 1];
  }
  double max = 0;
  for (int i=0; i<n-k+1; i++) max = Max(sumk[i], max);
  printf("%lf\n", (max+k)/2);
  return 0;
}
