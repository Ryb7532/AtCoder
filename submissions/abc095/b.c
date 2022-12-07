#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  int m[n];
  for (int i=0; i<n; i++) scanf("%d", m+i);
  int sum=0, min=1001;
  for (int i=0; i<n; i++) {
    sum+=m[i];
    min = (min > m[i]) ? m[i] : min;
  }
  int ans = n;
  x -= sum;
  ans += x/min;
  printf("%d\n", ans);
  return 0;
}
