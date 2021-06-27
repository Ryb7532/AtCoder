#include <stdio.h>
#include <stdlib.h>

int cmp(const void *x, const void *y) {
  return *(int *)x - *(int *)y;
}

int main() {
  int n;
  scanf("%d", &n);
  int d[n];
  for (size_t i = 0; i < n; i++) {
    scanf("%d", d+i);
  }
  qsort(d, n, sizeof(int), cmp);
  printf("%d\n", d[n/2] - d[n/2-1]);
  return 0;
}
