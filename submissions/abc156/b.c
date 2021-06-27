#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int ans = 0;
  while (n!=0) {
    ans++;
    n/=k;
  }
  printf("%d\n", ans);
  return 0;
}
