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
  int n, m;
  scanf("%d%d", &n, &m);
  int a[n]; double sum = 0;
  for (int i=0; i<n; i++) {
    scanf("%d", a+i);
    sum += a[i];
  }
  sum /= 4*m;
  qsort(a, n, sizeof(int), des);
  for (int i=0; i<m; i++) {
    if (a[i] < sum) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}
