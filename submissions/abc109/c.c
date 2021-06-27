#include <stdio.h>
#include <stdlib.h>

//GCD
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  int cx, d, ans = 0;
  for (int i=0; i<n; i++) {
    scanf("%d", &cx);
    d = abs(cx - x);
    ans = gcd(d, ans);
  }
  printf("%d", ans);
  return 0;
}
