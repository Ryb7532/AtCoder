#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define Max(a, b) (a > b ? a : b)

int main() {
  int n, z, w;
  scanf("%d%d%d", &n, &z, &w);
  int a[n];
  for (int i=0; i<n; i++)
    scanf("%d", a+i);
  int ans;
  if (n == 1)
    ans = abs(a[n-1]-w);
  else
    ans = Max(abs(a[n-1]-w), abs(a[n-2]-a[n-1]));
  printf("%d\n", ans);
  return 0;
}
