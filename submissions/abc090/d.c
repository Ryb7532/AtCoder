#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  long n, k;
  scanf("%ld%ld", &n, &k);
  long ans = 0;
  for (int i=k+1; i<n+1; i++) {
    long p = n/i, q = n%i;
    ans += (i-k)*p;
    if (k == 0) ans--;
    ans += (q>=k) ? q+1-k : 0;
  }
  printf("%ld\n", ans);
  return 0;
}
