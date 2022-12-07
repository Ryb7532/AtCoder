#include <stdio.h>

int main() {
  int a, b, ans;
  scanf("%d %d", &a, &b);
  if (a >= 13) {
    ans = b;
  }else if (a >= 6) {
    ans = b / 2;
  }else {
    ans = 0;
  }
  printf("%d\n", ans);
  return 0;
}
