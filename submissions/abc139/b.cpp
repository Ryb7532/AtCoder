#include <stdio.h>

int main() {
  int a, b, s = 1, ans = 0;
  scanf("%d%d", &a, &b);
  while (s < b) {
    ans++;
    s += a-1;
  }
  printf("%d\n", ans);
  return 0;
}
