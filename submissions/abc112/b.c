#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define OVER 10000

typedef struct root{
  int cost;
  int time;
}root;

int cmp_time(const void *x, const void *y) {
  return ((root *)x)->time - ((root *)y)->time;
}

int cmp_cost(const void *x, const void *y) {
  return ((root *)x)->cost - ((root *)y)->cost;
}

int main() {
  int n, t, j=0;
  scanf("%d%d", &n, &t);
  root a[n+1];
  for (int i=0; i<n; i++) scanf("%d%d", &(a[i].cost), &(a[i].time));
  a[n].cost = OVER;
  a[n].time = t+1;
  qsort(a, n+1, sizeof(root), cmp_time);
  while (a[j].time<=t) {
    j++;
  }
  if (j==0) {
    printf("TLE\n");
    return 0;
  }
  qsort(a, j, sizeof(root), cmp_cost);
  printf("%d\n", a[0].cost);
  return 0;
}
