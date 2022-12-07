#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
#include <math.h>

int main() {
  int a, b, c, dig = 1, d;
  scanf("%d%d", &a, &b);
  c = b;
  while (c != 0) {
    dig *= 10;
    c /= 10;
  }
  a = a*dig + b;
  d = (int)sqrt((double)a);
  if (a == d * d) printf("Yes\n");
  else printf("No\n");
  return 0;
}
