#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int x;
  scanf("%d", &x);
  long ans = 0;
  ans += 1000 * (x/500);
  x %= 500;
  ans += 5 * (x/5);
  printf("%ld\n", ans);
  return 0;
}
