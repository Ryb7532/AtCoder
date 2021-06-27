#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define Min(a, b) (a < b ? a : b)

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int x[n];
  for (int i=0; i<n; i++)
    scanf("%d", x+i);
  int ans = 0;
  for (int i=0; i<n; i++) {
    ans += Min(2*x[i], 2*(k-x[i]));
  }
  printf("%d\n", ans);
  return 0;
}
