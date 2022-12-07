#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n, k, m;
  scanf("%d %d %d", &n, &k, &m);
  int sum = 0, a;
  for (int i=0; i<n-1; i++) {
    scanf("%d", &a);
    sum += a;
  }
  int ans;
  if (m*n - sum < 0) ans = 0;
  else if (m*n - sum > k) ans = -1;
  else ans = m*n - sum;
  printf("%d\n", ans);
  return 0;
}
