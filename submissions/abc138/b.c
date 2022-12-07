#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  double a[n], b = 0.00;
  for (size_t i = 0; i < n; i++) {
    scanf("%lf", a+i);
    b += 1/a[i];
  }
  printf("%lf\n", 1/b);
  return 0;
}
