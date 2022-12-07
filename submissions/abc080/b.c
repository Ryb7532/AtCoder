#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int x;
  scanf("%d", &x);
  int sum = 0, y = x;
  while (y != 0) {
    sum += y%10;
    y /= 10;
  }
  if (x%sum)
    printf("No\n");
  else
    printf("Yes\n");
  return 0;
}
