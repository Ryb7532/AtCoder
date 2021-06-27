#include <stdio.h>

int gcd(int a, int b) {
  if (a == 0) {
    return b;
  } else if (b == 0) {
    return a;
  } else {
    return gcd(b, a%b);
  }
}

int main() {
  int a, b, k, g, i;
  scanf("%d%d%d", &a, &b, &k);
  g = gcd(a, b);
  for (i = g; i > 0; i--) {
    if (a%i == 0 && b%i == 0) {
      k--;
    }
    if (k == 0) {
      break;
    }
  }
  printf("%d\n", i);
  return 0;
}
