#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  int l, r, t[n+1][n+1], ans[q];
  for (int i=0; i<n+1; i++) for (int j=0; j<n+1; j++) t[i][j] = 0;
  for (int i=0; i<q; i++) ans[i] = 0;
  for (int i=0; i<m; i++) {
    scanf("%d%d", &l, &r);
    t[l][r]++;
  }
  for (int i=0; i<n+1; i++) for (int j=1; j<n+1; j++) t[i][j] += t[i][j-1];
  for (int i=0; i<q; i++) {
    scanf("%d%d", &l, &r);
    for (int j=l; j<r+1; j++) ans[i] += t[j][r] - t[j][l-1];
  }
  for (int i=0; i<q; i++) printf("%d\n", ans[i]);
  return 0;
}
