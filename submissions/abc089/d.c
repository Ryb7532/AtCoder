#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define Max(a, b) (a > b ? a : b)

typedef struct grid{
  int x;
  int y;
  int a;
} grid;

//昇順
int a_acs(const void *a, const void *b)
{
  return ((grid *)a)->a - ((grid *)b)->a;
}

int main() {
  int h, w, d;
  scanf("%d%d%d", &h, &w, &d);
  grid g[h*w];
  for (int i=0; i<h; i++)
    for (int j=0; j<w; j++) {
      scanf("%d", &(g[i*w+j].a));
      g[i*w+j].x = i+1;
      g[i*w+j].y = j+1;
    }
  int q;
  scanf("%d", &q);
  int l[q], r[q];
  for (int i=0; i<q; i++)
    scanf("%d%d", l+i, r+i);
  qsort(g, h*w, sizeof(grid), a_acs);
  long cost[h*w];
  for (int i=0; i<d; i++)
    cost[i] = 0;
  for (int i=d; i<h*w; i++)
    cost[i] = cost[i-d] + abs(g[i-d].x - g[i].x) + abs(g[i-d].y - g[i].y);
  for (int i=0; i<q; i++)
    printf("%ld\n", cost[r[i]-1]-cost[l[i]-1]);
  return 0;
}
