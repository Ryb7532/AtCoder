#include <stdio.h>

int main() {
  int r, d, x;
  scanf("%d %d %d", &r ,&d, &x);
  for (int i = 0; i < 10; i++) {
    x = r * x - d;
    printf("%d\n", x);
  }
  return 0;
}
