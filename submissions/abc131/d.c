#include <stdio.h>
#include <stdlib.h>

typedef struct time{
  int a;
  int b;
} time;

int cmp(const void *x, const void *y) {
  return (*(time *)x).b - (*(time *)y).b;
}

int main() {
  int n; long int sum = 0;
  scanf("%d", &n);
  time t[n];
  for (size_t i = 0; i < n; i++) {
    scanf("%d %d", &(t[i].a), &(t[i].b));
  }
  qsort(t, n, sizeof(time), cmp);
  for (size_t i = 0; i < n; i++) {
    sum += t[i].a;
    if (sum > t[i].b) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}
