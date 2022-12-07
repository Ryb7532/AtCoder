#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

//昇順
int acs(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int main() {
  int n;
  scanf("%d", &n);
  int x[n], a[n];
  for (int i=0; i<n; i++) {
    scanf("%d", x+i);
    a[i] = x[i];
  }
  qsort(a, n, sizeof(int), acs);
  for (int i=0; i<n; i++) {
    if (x[i] <= a[n/2-1]) printf("%d\n", a[n/2]);
    else printf("%d\n", a[n/2-1]);
  }
  return 0;
}
