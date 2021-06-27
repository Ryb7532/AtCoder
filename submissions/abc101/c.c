#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int ans = (n-2)/(k-1)+1;
  printf("%d\n", ans);
  return 0;
}
