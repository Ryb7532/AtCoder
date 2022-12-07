#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  int p[n];
  for (int i=0; i<n; i++) scanf("%d", p+i);
  int min = n+1, ans = 0;
  for (int i=0; i<n; i++) {
    if (min > p[i]) {
      ans++;
      min = p[i];
    }
  }
  printf("%d\n", ans);
  return 0;
}
