#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  int l, r, ans = 0;
  for (int i=0; i<n; i++) {
    scanf("%d%d", &l, &r);
    ans += r-l+1;
  }
  printf("%d\n", ans);
  return 0;
}
