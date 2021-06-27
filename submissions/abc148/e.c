#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  long n;
  scanf("%ld", &n);
  if (n%2 == 1) {
    printf("0\n");
    return 0;
  }
  long ans = n/10;
  n /= 10;
  while (n != 0) {
    ans += n/5;
    n /= 5;
  }
  printf("%ld\n", ans);
  return 0;
}
