#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define MIN(a, b) ((a<b) ? a : b)

int main() {
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  printf("%d\n", MIN(a, b) + MIN(c, d));
  return 0;
}
