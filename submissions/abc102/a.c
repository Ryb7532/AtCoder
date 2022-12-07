#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  if (n%2 == 0) printf("%d\n", n);
  else printf("%d\n", 2*n);
  return 0;
}
