#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int main() {
  int n, k, min = INT_MAX;
  scanf("%d%d", &n, &k);
  int h[n];
  for (size_t i = 0; i < n; i++) {
    scanf("%d", h+i);
  }
  qsort(h, n, sizeof(int), cmp);
  for (size_t i = 0; i <= n-k; i++) {
    int tmp = h[k+i-1] - h[i];
    min = (tmp < min) ? tmp : min;
  }
  printf("%d\n", min);
  return 0;
}
