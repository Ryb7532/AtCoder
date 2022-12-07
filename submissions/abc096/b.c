#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

#define MAX(a, b) ((a>b) ? a : b)
#define MAX3(a, b, c) (MAX(MAX(a, b), c))

int main() {
  int a, b, c, k;
  scanf("%d%d%d", &a, &b, &c);
  scanf("%d", &k);
  int ans = a+b+c, max = MAX3(a, b, c);
  ans += -max + max*(1<<k);
  printf("%d\n", ans);
  return 0;
}
