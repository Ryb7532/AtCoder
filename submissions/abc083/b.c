#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n, a, b, ans = 0;
  scanf("%d%d%d", &n, &a, &b);
  for (int i=1; i<=n; i++) {
    int c = i, sum = 0;
    while (c != 0) {
      sum += c % 10;
      c /= 10;
    }
    if (a <= sum && sum <= b) ans += i;
  }
  printf("%d\n", ans);
  return 0;
}
