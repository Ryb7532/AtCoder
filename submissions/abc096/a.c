#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  int ans = 0;
  ans += a-1;
  if (b>=a) ans++;
  printf("%d\n", ans);
  return 0;
}
