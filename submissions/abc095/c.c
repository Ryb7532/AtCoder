#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int a, b, c, x, y;
  scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
  int ans;
  if (a+b < 2*c) ans = a*x + b*y;
  else {
    int rest;
    if (x<y) {
      rest = y-x;
      ans = 2*c*x;
      ans += (rest*b < rest*2*c) ? rest*b : rest*2*c;
    } else {
      rest = x-y;
      ans = 2*c*y;
      ans += (rest*a < rest*2*c) ? rest*a : rest*2*c;
    }
  }
  printf("%d\n", ans);
  return 0;
}
