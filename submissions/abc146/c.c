#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int digit(long a) {
  int ans = 0;
  while (a != 0) {
    ans++;
    a /= 10;
  }
  return ans;
}

int main() {
  long a, b, x;
  scanf("%ld%ld%ld", &a, &b, &x);
  long bot = 0, top = 1000000001, mid;
  while (top - bot > 1) {
    mid = (top + bot) / 2;
    if (a*mid + b*digit(mid) <= x) bot = mid;
    else top = mid;
  }
  printf("%ld\n", bot);
  return 0;
}
