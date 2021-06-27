#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  long n;
  scanf("%ld", &n);
  if (n == 2) {
    printf("1\n");
    return 0;
  }
  long ans = 2;
  for (long i=2; i*i<=n; i++) {
    if (i*i == n-1)
      ans++;
    else if ((n-1)%i == 0)
      ans += 2;
    if (n%i != 0)
      continue;
    long p = n / i, m = n;
    while (m%i == 0)
      m /= i;
    if (m%i == 1)
      ans++;
    m = n;
    while (m%p == 0)
      m /= p;
    if (m%p == 1 && i!=p)
      ans++;
  }
  printf("%ld\n", ans);
  return 0;
}
