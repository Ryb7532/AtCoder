#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

//降順
int des(const void *a, const void *b)
{
  return *(long *)b - *(long *)a;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  long h[n];
  for (int i=0; i<n; i++) scanf("%ld", h+i);
  qsort(h, n, sizeof(long), des);
  if (n <= k) {
    printf("0\n");
    return 0;
  }
  long ans = 0;
  for (int i=k; i<n; i++) ans += h[i];
  printf("%ld\n", ans);
  return 0;
}
