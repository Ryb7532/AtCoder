#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  int d, x, a[n];
  scanf("%d%d", &d, &x);
  for (int i=0; i<n; i++) scanf("%d", a+i);
  int ans = x;
  for (int i=0; i<n; i++) ans += (d-1)/a[i] + 1;
  printf("%d\n", ans);
  return 0;
}
