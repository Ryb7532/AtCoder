#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct restraunt {
  char city[10];
  int point;
  int number;
} RESTRAUNT;

int compare(const void *a, const void *b) {
  RESTRAUNT ra = *(RESTRAUNT *)a, rb = *(RESTRAUNT *)b;
  int cmp = strcmp(ra.city, rb.city);
  if (cmp == 0) {
    return rb.point - ra.point;
  } else {
    return cmp;
  }
}

int main() {
  int n;
  scanf("%d\n", &n);
  RESTRAUNT a[n];
  for (int i = 0; i < n; i++) {
    scanf("%s%d", a[i].city, &(a[i].point));
    a[i].number = i+1;
  }
  qsort(a, n, sizeof(RESTRAUNT), compare);
  for (size_t i = 0; i < n; i++) {
    printf("%d\n", a[i].number);
  }
  return 0;
}
