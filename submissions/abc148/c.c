#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

long gcd(long a, long b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  long a, b;
  scanf("%ld %ld", &a, &b);
  long g = gcd(a, b);
  printf("%ld\n", a*b/g);
  return 0;
}
