#include <stdio.h>

int main() {
  int a, b, ans = 0;
  scanf("%d %d", &a, &b);
  for (int i = 0; i < 2; i++) {
    if (a > b) {
      ans += a;
      a -= 1;
    }else {
      ans += b;
      b -= 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
