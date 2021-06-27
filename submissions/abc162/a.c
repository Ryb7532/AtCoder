#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  if (n%10 == 7 || (n/10)%10 == 7 || n/100 == 7)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
