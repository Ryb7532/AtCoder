#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define Min(a, b) (a < b ? a : b)

int main() {
  long n, a, b;
  scanf("%ld%ld%ld", &n ,&a, &b);
  long ans;
  ans = n/(a+b)*a;
  ans += Min(n%(a+b), a);
  printf("%ld\n", ans);
  return 0;
}
