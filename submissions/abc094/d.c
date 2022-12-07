#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define MIN(a, b) ((a<b) ? a : b)

//降順
int des(const void *a, const void *b) {
  return *(int *)b - *(int *)a;
}

int main() {
  int n;
  scanf("%d", &n);
  int a[n], l, r, s=1000000000;
  for (int i=0; i<n; i++) scanf("%d", a+i);
  qsort(a, n, sizeof(int), des);
  l=a[0];
  if (l%2 == 1) {
    for (int i=1; i<n; i++) {
      int sub = MIN(abs(a[i]-l/2), abs(a[i]-l/2-1));
      if (s>sub) {
        s=sub;
        r=a[i];
      }
    }
  } else {
    for (int i=1; i<n; i++) {
      int sub = abs(a[i]-l/2);
      if (s>sub) {
        s=sub;
        r=a[i];
      }
    }
  }
  printf("%d %d\n", l, r);
  return 0;
}
