#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  int a, ans = 0;
  for (int i=0; i<n; i++) {
    scanf("%d", &a);
    ans += a-1;
  }
  printf("%d\n", ans);
  return 0;
}
