#include <stdio.h>
#include <stdlib.h>

typedef struct city {
  int idx;
  int year;
  int prefecture;
  int order;
} city;

int cmp_year(const void *x, const void *y) {
  if (((city *)x)->prefecture == ((city *)y)->prefecture) return ((city *)x)->year-((city *)y)->year;
  else return ((city *)x)->prefecture-((city *)y)->prefecture;
}

int cmp_idx(const void *x, const void *y) {
  return ((city *)x)->idx-((city *)y)->idx;
}

int main() {
  int n, m, num = 1, pre = 0;
  scanf("%d%d", &n, &m);
  city a[m];
  for (int i=0; i<m; i++) {
    scanf("%d%d", &(a[i].prefecture), &(a[i].year));
    a[i].idx = i;
  }
  qsort(a, m, sizeof(city), cmp_year);
  for (int i=0; i<m; i++) {
    if (pre == a[i].prefecture) {
      a[i].order = num;
      num++;
    } else {
      pre = a[i].prefecture;
      num = 1;
      a[i].order = num;
      num++;
    }
  }
  qsort(a, m, sizeof(city), cmp_idx);
  for (int i=0; i<m; i++) {
    printf("%06d%06d\n", a[i].prefecture, a[i].order);
  }
  return 0;
}
