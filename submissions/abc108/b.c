#include <stdio.h>

int main() {
  int x1, y1, x2, y2;
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  int x3, y3, x4, y4;
  x3 = x2-y2+y1;
  y3 = y2+x2-x1;
  x4 = x1-y2+y1;
  y4 = y1+x2-x1;
  printf("%d %d %d %d\n", x3, y3, x4, y4);
  return 0;
}
