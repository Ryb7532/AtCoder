#include <stdio.h>
#include <stdlib.h>

struct card{
  int b;
  long int c;
};

int asc(const void *a, const void *b) {
  if(*(long*)a - *(long*)b > 0) {
    return 1;
  } else {
    return -1;
  }
}

int desc(const void *a, const void *b) {
  if (((struct card*)b)->c - ((struct card*)a)->c > 0) {
    return 1;
  } else {
    return -1;
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  long int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%ld", a+i);
  }
  qsort(a, n, sizeof(long int), asc);
  struct card p[m];
  for (int i = 0; i < m; i++) {
    scanf("%d %ld", &(p[i].b), &(p[i].c));
  }
  qsort(p, m, sizeof(struct card), desc);
  int j = 0, k = 0, l = 0;
  while ((k < m) && (j < n)) {
    if (a[j] < p[k].c) {
      a[j] = p[k].c;
      l++;
      if (p[k].b <= l) {
        k++;
        l=0;
      }
    }
    j++;
  }
  long int ans=0;
  for (int i = 0; i < n; i++) {
    ans += a[i];
  }
  printf("%ld\n", ans);
  return 0;
}
