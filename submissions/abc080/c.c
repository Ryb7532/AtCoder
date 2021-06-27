#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
#include <limits.h>
//#include <math.h>

#define Max(a, b) (a > b ? a : b)

int main() {
  int n;
  scanf("%d", &n);
  int f[n][10], p[n][11];
  for (int i=0; i<n; i++)
    for (int j=0; j<10; j++)
      scanf("%d", f[i]+j);
  for (int i=0; i<n; i++)
    for (int j=0; j<11; j++)
      scanf("%d", p[i]+j);
  int ans = INT_MIN, profit, cnt;
  for (int i=1; i<(1<<10); i++) {
    profit = 0;
    for (int j=0; j<n; j++) {
      cnt = 0;
      for (int k=0; k<10; k++)
        if ((i & (1<<k)) != 0 && f[j][k] == 1)
          cnt++;
      profit += p[j][cnt];
    }
    ans = Max(ans, profit);
  }
  printf("%d\n", ans);
  return 0;
}
