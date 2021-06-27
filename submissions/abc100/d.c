//WA
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

//降順
int des(const void *a, const void *b) {
  return *(long *)b - *(long *)a;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  long x, y, z, a[8][n], sum[8], ans = 0;
  for (int i=0; i<8; i++) sum[i] = 0;
  for (int i=0; i<n; i++) {
    scanf("%ld%ld%ld", &x, &y, &z);
    a[0][i] = x+y+z;
    a[1][i] = x+y-z;
    a[2][i] = x-y+z;
    a[3][i] = x-y-z;
    a[4][i] = -x+y+z;
    a[5][i] = -x+y-z;
    a[6][i] = -x-y+z;
    a[7][i] = -x-y-z;
  }
  for (int i=0; i<8; i++) /*qsort(a[i], n, sizeof(long), des);*/{
    for (int j=0; j<n-1; j++) {
      for (int k=j+1; k<n; k++) {
        if (a[i][j] < a[i][k]) {
          long tmp = a[i][j];
          a[i][j] = a[i][k];
          a[i][k] = tmp;
        }
      }
    }
  }
  for (int i=0; i<8; i++) for (int j=0; j<m; j++) sum[i] += a[i][j];
  for (int i=0; i<8; i++) ans = (ans < sum[i]) ? sum[i] : ans;
  printf("%ld\n", ans);
  return 0;
}
