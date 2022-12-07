#include <stdio.h>
#include <stdlib.h>

typedef struct student{
  int number;
  int order;
}stu;

int cmp_order(const void *x, const void *y) {
  return ((stu *)x)->order - ((stu *)y)->order;
}

int main() {
  int n;
  scanf("%d", &n);
  stu a[n];
  for (int i=0; i<n; i++) {
    scanf("%d", &(a[i].order));
    a[i].number = i+1;
  }
  qsort(a, n, sizeof(stu), cmp_order);
  for (int i=0; i<n; i++) printf("%d ", a[i].number);
  printf("\n");
  return 0;
}
