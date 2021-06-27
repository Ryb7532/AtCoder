#include <stdio.h>

int main() {
  int n, k;
  scanf("%d%d", &n ,&k);
  long d = n/k; long ans = 0;
  ans += d*d*d;
  if (k%2 == 0) {
    d = n/(k/2) - d;
    ans += d*d*d;
  }
  printf("%ld\n", ans);
  return 0;
}
