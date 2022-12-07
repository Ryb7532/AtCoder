#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int p[m]; char s[m][5];
  for (int i=0; i<m; i++) scanf("%d %s", p+i, s[i]);
  int ac = 0, wa = 0, a[n];
  for (int i=0; i<n; i++) a[i] = 0;
  for (int i=0; i<m; i++) {
    if (a[p[i]-1] == -1) continue;
    if (s[i][0] == 'W') a[p[i]-1]++;
    else {
      ac++;
      wa += a[p[i]-1];
      a[p[i]-1] = -1;
    }
  }
  printf("%d %d\n", ac, wa);
  return 0;
}
