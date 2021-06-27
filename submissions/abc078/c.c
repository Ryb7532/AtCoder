#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int ans;
  ans = n-m;
  ans += 19*m;
  for (int i=0; i<m; i++)
    ans *= 2;
  ans *= 100;
  printf("%d\n", ans);
  return 0;
}
