#include <stdio.h>

int main () {
  int x, a;
  scanf("%d %d", &x, &a);
  int ans = (x<a) ? 0 : 10;
  printf("%d\n", ans);
  return 0;
}
