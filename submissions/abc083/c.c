#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  long x, y;
  scanf("%ld%ld", &x, &y);
  long ans = 0;
  while (x <= y) {
    ans++;
    x *= 2;
  }
  printf("%ld\n", ans);
  return 0;
}
