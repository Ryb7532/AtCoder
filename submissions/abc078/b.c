#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int x, y, z;
  scanf("%d%d%d", &x, &y, &z);
  int ans = 1;
  x -= y+2*z;
  ans += x/(y+z);
  printf("%d\n", ans);
  return 0;
}
