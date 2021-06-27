#include <stdio.h>

int gcd (int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a%b);
}
int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  int b[n], c[n];
  b[0] = 0;
  c[n-1] = 0;
  for (int i = 1; i < n; i++) {
    b[i] = gcd(a[i-1], b[i-1]);
  }
  for (int i = n-1; i > 0 ; i--) {
    c[i-1] = gcd(a[i], c[i]);
  }
  int max = 0, x;
  for (size_t i = 0; i < n; i++) {
    x = gcd(b[i], c[i]);
    if (max < x) {
      max = x;
    }
  }
  printf("%d\n", max);
  return 0;
}
