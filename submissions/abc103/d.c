#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

typedef struct war{
  int a;
  int b;
}War;

//昇順
int acs(const void *a, const void *b) {
  if (((War *)a)->a == ((War *)b)->a) return ((War *)a)->b - ((War *)b)->b;
  return ((War *)a)->a - ((War *)b)->a;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  War w[m];
  for (int i=0; i<m; i++) scanf("%d%d", &(w[i].a), &(w[i].b));
  int ans = 1, min = w[0].b;
  qsort(w, m, sizeof(War), acs);
  for (int i=0; i<m; i++) {
    if (w[i].a < min) {
      min = (min > w[i].b) ? w[i].b : min;
      continue;
    }
    ans++;
    min = w[i].b;
  }
  printf("%d\n", ans);
  return 0;
}
