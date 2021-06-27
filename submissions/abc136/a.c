#include <stdio.h>

int main() {
  int a, b, c, ans;
  scanf("%d%d%d", &a, &b, &c);
  ans = (c>a-b) ? c-(a-b) : 0;
  printf("%d\n", ans);
  return 0;
}
