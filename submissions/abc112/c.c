#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX(a, b) ((a > b)?a:b)

typedef struct point{
  int x;
  int y;
  int h;
}point;

int cmp(const void *x, const void *y) {
  return ((point *)y)->h - ((point *)x)->h;
}

int main() {
  int n, ansh, k;
  scanf("%d", &n);
  point a[n];
  for (int i=0; i<n; i++) {
    scanf("%d%d%d", &(a[i].x), &(a[i].y), &(a[i].h));
  }
  qsort(a, n, sizeof(point), cmp);
  for (int i=0; i<=100; i++) {
    for (int j=0; j<=100; j++) {
      ansh = a[0].h + abs(a[0].x-i) + abs(a[0].y-j);
      for (k=1; k<n; k++) {
        if (MAX(ansh-abs(a[k].x-i)-abs(a[k].y-j), 0) == a[k].h) continue;
        else break;
      }
      if (k==n) {
        printf("%d %d %d\n", i, j, ansh);
        return 0;
      }
    }
  }
  return 0;
}
