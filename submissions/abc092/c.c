#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define MIN(a, b) ((a<b) ? a : b)

int main() {
  int n;
  scanf("%d", &n);
  int a[n+2], sum=0, ans;
  a[0]=0; a[n+1]=0;
  for (int i=1; i<=n; i++) {
    scanf("%d", a+i);
    sum+=abs(a[i-1]-a[i]);
  }
  sum+=abs(a[n]);
  for (int i=1; i<=n; i++) {
    ans = sum;
    ans -= abs(a[i-1]-a[i]) + abs(a[i]-a[i+1]);
    ans += abs(a[i-1]-a[i+1]);
    printf("%d\n", ans);
  }
  return 0;
}
