#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  long n, k;
  scanf("%ld%ld", &n, &k);
  long r = n%k;
  long ans = (2*r < k) ? r : k-r;
  printf("%ld\n", ans);
  return 0;
}
