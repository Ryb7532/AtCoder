#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

typedef struct Coordinate{
  int x;
  int y;
}point;

//昇順
int acs(const void *a, const void *b) {
  return ((point *)a)->x - ((point *)b)->x;
}

int main() {
  int n;
  scanf("%d", &n);
  point r[n], b[n]; int ans = 0;
  for (int i=0; i<n; i++) scanf("%d%d", &(r[i].x), &(r[i].y));
  for (int i=0; i<n; i++) scanf("%d%d", &(b[i].x), &(b[i].y));
  qsort(b, n, sizeof(point), acs);
  for (int i=0; i<n; i++) {
    int k=-1, max=-1;
    for (int j=0; j<n; j++) {
      if (b[i].x > r[j].x && b[i].y > r[j].y) {
        if (max < r[j].y) {
          max = r[j].y;
          k=j;
        }
      }
    }
    if (k!=-1) {
      ans++;
      r[k].x = -1;
      r[k].y = -1;
    }
  }
  printf("%d\n", ans);
  return 0;
}