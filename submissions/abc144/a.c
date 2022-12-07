#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  if (a>9 || b>9) printf("%d\n", -1);
  else printf("%d\n", a*b);
  return 0;
}
