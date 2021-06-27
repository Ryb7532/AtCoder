#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n, m;
  scanf("%d", &n);
  char s[n][11];
  for (int i=0; i<n; i++) scanf("%s", s[i]);
  scanf("%d", &m);
  char t[m][11];
  for (int i=0; i<m; i++) scanf("%s", t[i]);
  int ans=0;
  for (int i=0; i<n; i++) {
    int cnt=1;
    for (int j=i+1; j<n; j++) {
      if (strcmp(s[i], s[j]) == 0) cnt++;
    }
    for (int j=0; j<m; j++) {
      if (strcmp(s[i], t[j]) == 0) cnt--;
    }
    ans = (ans<cnt) ? cnt : ans;
  }
  printf("%d\n", ans);
  return 0;
}
