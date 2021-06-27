#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

//昇順
int acs(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int main() {
  int n;
  scanf("%d", &n);
  int tmp, a[n], b; long ans = 0;
  for (int i=0; i<n; i++) {
    scanf("%d", &tmp);
    a[i] = tmp-i-1;
  }
  qsort(a, n, sizeof(int), acs);
  b = a[n/2];
  for (int i=0; i<n; i++) ans += abs(a[i]-b);
  printf("%ld\n", ans);
  return 0;
}
