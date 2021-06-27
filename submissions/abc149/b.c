#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  long a, b, k;
  scanf("%ld %ld %ld", &a, &b, &k);
  if (a+b < k)
    printf("0 0\n");
  else if (a < k)
    printf("0 %ld\n", a+b-k);
  else
    printf("%ld %ld\n", a-k, b);
  return 0;
}
