#include <stdio.h>

int main() {
  int a, b, c, ans = 0;
  scanf("%d%d%d", &a, &b, &c);
  if (a*c >= b) {
    ans = b/a;
  } else {
    ans = c;
  }
  printf("%d\n", ans);
  return 0;
}
