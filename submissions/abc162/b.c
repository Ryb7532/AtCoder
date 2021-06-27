#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  long ans = 0;
  for (int i=1; i<=n; i++) {
    if (i%3 != 0 && i%5 != 0)
      ans += i;
  }
  printf("%ld\n", ans);
  return 0;
}
