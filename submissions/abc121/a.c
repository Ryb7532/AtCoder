#include <stdio.h>

int main() {
  int h, w, x, y;
  scanf("%d%d", &h, &w);
  scanf("%d%d", &x, &y);
  int ans = (h-x)*(w-y);
  printf("%d\n", ans);
  return 0;
}
