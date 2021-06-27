#include <stdio.h>

int main() {
  long double n, t = 0.0;
  int k;
  scanf("%Lf %d", &n, &k);
  for (int i = 0; i < n; i++) {
    int s = i + 1;
    long double l = 1.0/n;
    while (s < k) {
      s *= 2;
      l *= 1.0/2.0;
    }
    t += l;
  }
  printf("%.12Lf\n", t);
  return 0;
}
