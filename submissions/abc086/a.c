#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  if (a%2 == 0 || b%2 == 0)
    printf("Even\n");
  else printf("Odd\n");
  return 0;
}
