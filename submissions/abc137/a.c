#include <stdio.h>

int Max(int x, int y) {
  return (x>y) ? x : y;
}

int main() {
  int a, b, max;
  scanf("%d%d", &a, &b);
  max = Max(a+b, a-b);
  max = Max(max, a*b);
  printf("%d\n", max);
  return 0;
}
