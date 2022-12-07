#include <stdio.h>

long int gcd(long long int a, long long int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a%b);
}

int main() {
  long long int a, b, lcm, ans, c, d;
  scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
  lcm = c*d/gcd(c, d);
  ans = b-a+1;
  ans -= b/c - (a-1)/c;
  ans -= b/d -(a-1)/d;
  ans += b/lcm - (a-1)/lcm;
  printf("%lld\n", ans);
  return 0;
}
