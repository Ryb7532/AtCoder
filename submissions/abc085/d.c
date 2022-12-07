#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

//降順
int des(const void *a, const void *b)
{
  return *(int *)b - *(int *)a;
}

int main() {
  int n, h;
  scanf("%d%d", &n, &h);
  int a[n], b[n];
  for (int i=0; i<n; i++)
    scanf("%d %d", a+i, b+i);
  int ans = 0, amax;
  qsort(a, n, sizeof(int), des);
  qsort(b, n, sizeof(int), des);
  amax = a[0];
  for (int i=0; i<n; i++) {
    if (h <= 0) break;
    if (b[i] < amax) break;
    h -= b[i];
    ans++;
  }
  if (h > 0) {
    ans += (h-1)/amax+1;
  }
  printf("%d\n", ans);
  return 0;
}
