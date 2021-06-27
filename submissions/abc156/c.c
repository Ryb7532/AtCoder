#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
#include <limits.h>
//#include <math.h>

#define Min(a, b) (a < b ? a : b)

int main() {
  int n;
  scanf("%d", &n);
  int x[n];
  for (int i=0; i<n; i++)
    scanf("%d", x+i);
  int ans = INT_MAX, cnt;
  for (int i=1; i<101; i++) {
    cnt = 0;
    for (int j=0; j<n; j++) {
      cnt += (x[j]-i)*(x[j]-i);
    }
    ans = Min(ans, cnt);
  }
  printf("%d\n", ans);
  return 0;
}
