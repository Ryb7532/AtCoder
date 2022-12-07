#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

#define MAX(a, b) ((a>b) ? a : b)

int main() {
  int a1, a2, a3;
  scanf("%d%d%d", &a1, &a2, &a3);
  int s12, s23, s13, ans;
  s12 = abs(a1-a2);
  s23 = abs(a2-a3);
  s13 = abs(a1-a3);
  ans = s12 + s23 + s13 - MAX(MAX(s12, s23), s13);
  printf("%d\n", ans);
  return 0;
}
