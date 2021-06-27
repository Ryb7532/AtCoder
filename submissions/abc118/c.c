#include <stdio.h>

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a%b);
  }
}

int main() {
  int n, ans = 0, a;
  scanf("%d", &n);
  for (size_t i = 0; i < n; i++) {
    scanf("%d", &a);
    ans = gcd(a, ans);
  }
  printf("%d\n", ans);
  return 0;
}
