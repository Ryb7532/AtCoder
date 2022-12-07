#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n, r;
  scanf("%d%d", &n, &r);
  int ans;
  if (n>=10)
    ans = r;
  else
    ans = r + 100*(10-n);
  printf("%d\n", ans);
  return 0;
}
