#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int k, x;
  scanf("%d %d", &k, &x);
  if (500 * k >= x)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
