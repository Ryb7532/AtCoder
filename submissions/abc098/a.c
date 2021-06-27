#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

#define MAX(a, b) ((a>b) ? a : b)
#define MAX3(a, b, c) (MAX(MAX(a, b), c))

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%d\n", MAX3(a+b, a-b, a*b));
  return 0;
}
