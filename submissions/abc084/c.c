#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  int c[n-1], s[n-1], f[n-1];
  for (int i=0; i<n-1; i++)
    scanf("%d%d%d", c+i, s+i, f+i);
  for (int i=0; i<n; i++) {
    int ans = 0;
    for (int j=i; j<n-1; j++) {
      if (ans <= s[j]) {
        ans = s[j]+c[j];
      } else {
        ans = ((ans - s[j]-1)/f[j] + 1)*f[j] + s[j] + c[j];
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
