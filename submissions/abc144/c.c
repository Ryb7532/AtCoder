#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <limits.h>
#include <math.h>

int main() {
  long n;
  scanf("%ld", &n);
  long ans = LONG_MAX;
  for (int i=1; i<sqrt((double)n)+1; i++) {
    if (n%i != 0) continue;
    long a = i-1 + (n/i)-1;
    ans = (ans<a) ? ans : a;
  }
  printf("%ld\n", ans);
  return 0;
}
