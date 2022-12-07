//WA

#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <limits.h>
//#include <math.h>

int main() {
  int n, c;
  scanf("%d%d", &n, &c);
  int d[c][c], g[n][n], cnt[3][c];
  for (int i=0; i<c; i++) for (int j=0; j<c; j++) scanf("%d", &(d[i][j]));
  for (int i=0; i<3; i++) for (int j=0; j<c; j++) cnt[i][j] = 0;
  for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
    scanf("%d", &(g[i][j]));
    g[i][j]--;
    cnt[(i+j)%3][g[i][j]]++;
  }
  int ans = INT_MAX, sum;
  for (int i=0; i<c; i++) {
    for (int j=0; j<c; j++) {
      if (i == j) continue;
      for (int k=0; k<c; k++) {
        if (i == k || j == k) continue;
        sum = 0;
        for (int l=0; l<c; l++) sum += cnt[0][l]*d[l][i] + cnt[1][l]*d[l][j] + cnt[2][l]*d[l][k];
        ans = (ans < sum) ? ans : sum;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
