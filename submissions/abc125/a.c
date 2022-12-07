#include <stdio.h>

int main() {
  int a, b, t;
  scanf("%d %d %d", &a, &b, &t);
  int ans = t / a * b;
  printf("%d\n", ans);
  return 0;
}
