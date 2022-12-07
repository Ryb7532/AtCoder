#include <stdio.h>
#include <limits.h>

int main() {
  long int n, a, min = LONG_MAX;
  scanf("%ld", &n);
  for (int i = 0; i < 5; i++) {
    scanf("%ld", &a);
    if (min > a) {
      min = a;
    }
  }
  long int ans = (n-1) / min + 5;
  printf("%ld\n", ans);
  return 0;
}
