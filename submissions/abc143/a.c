#include <stdio.h>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  int ans = (a-b*2>0) ? a-b*2 : 0;
  printf("%d\n", ans);
  return 0;
}
