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
  int a, ans=INT_MAX, cnt;
  for (int i=0; i<n; i++) {
    cnt = 0;
    scanf("%d", &a);
    while (a%2 == 0) {
      cnt++;
      a /= 2;
    }
    ans = Min(ans, cnt);
  }
  printf("%d\n", ans);
  return 0;
}
