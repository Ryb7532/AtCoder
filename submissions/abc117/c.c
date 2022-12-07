#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

int main() {
  int n, m, ans;
  scanf("%d%d", &n, &m);
  int x[m], d[m-1];
  for (size_t i = 0; i < m; i++) {
    scanf("%d", x+i);
  }
  qsort(x, m, sizeof(int), cmp);
  for (size_t i = 0; i < m-1; i++) {
    d[i] = x[i] - x[i+1];
  }
  qsort(d, m-1, sizeof(int), cmp);
  ans = x[0] - x[m-1];
  if (m <= n) {
    printf("0\n");
    return 0;
  }
  for (size_t i = 0; i < n-1; i++) {
    ans -= d[i];
  }
  printf("%d\n", ans);
  return 0;
}
