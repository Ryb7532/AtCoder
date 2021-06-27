#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define Min(a, b) (a < b ? a : b)

int main() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  printf("%d\n", Min(n*a, b));
  return 0;
}
