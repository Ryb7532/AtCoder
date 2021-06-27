#include <stdio.h>

int main() {
  int n, a, b, ans;
  scanf("%d%d%d", &n, &a, &b);
  ans = (n*a>b) ? b : n*a;
  printf("%d\n", ans);
  return 0;
}
