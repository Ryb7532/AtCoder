#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  if (a+b+c>21) printf("bust\n");
  else printf("win\n");
  return 0;
}
