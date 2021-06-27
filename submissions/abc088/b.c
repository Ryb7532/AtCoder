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
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i=0; i<n; i++)
    scanf("%d", a+i);
  qsort(a, n, sizeof(int), des);
  int ans = 0;
  for (int i=0; i<n; i++) {
    if (i%2 == 0) ans += a[i];
    else ans -= a[i];
  }
  printf("%d\n", ans);
  return 0;
}
