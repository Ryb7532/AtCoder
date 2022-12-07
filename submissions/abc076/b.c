#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n, k, ans = 1;
  scanf("%d%d", &n, &k);
  for (int i=0; i<n; i++) {
    if (ans < k)
      ans *= 2;
    else
      ans += k;
  }
  printf("%d\n", ans);
  return 0;
}
