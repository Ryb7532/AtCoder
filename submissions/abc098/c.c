#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  char s[n+1];
  scanf("%s", s);
  int e[n+1], w[n+1], ans = 300001;
  w[0] = 0; e[n] = 0;
  for (int i=1; i<n+1; i++) w[i] = (s[i-1] == 'W') ? w[i-1]+1 : w[i-1];
  for (int i=n-1; i>=0; i--) e[i] = (s[i] == 'E') ? e[i+1]+1 : e[i+1];
  for (int i=0; i<n; i++) {
    int cnt = w[i] + e[i+1];
    ans = (ans > cnt) ? cnt : ans;
  }
  printf("%d\n", ans);
  return 0;
}
