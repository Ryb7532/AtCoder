#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int x, a, b;
  scanf("%d", &x);
  scanf("%d", &a);
  scanf("%d", &b);
  printf("%d\n", (x-a)%b);
  return 0;
}
