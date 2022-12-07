#include <stdio.h>
#include <stdlib.h>

int cmp(const void *x, const void *y) {
  return *(double *)x - *(double *)y;
}

int main() {
  int n;
  scanf("%d", &n);
  double v[n], ans=0;
  for (int i=0; i<n; i++) scanf("%lf", v+i);
  qsort(v, n, sizeof(double), cmp);
  ans = v[0];
  for (int i=1; i<n; i++) {
    ans += v[i];
    ans = ans/2;
  }
  printf("%lf\n", ans);
  return 0;
}
