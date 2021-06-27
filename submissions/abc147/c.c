#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define max(a,b) (a > b ? a : b)

int main() {
  int n;
  scanf("%d", &n);
  int x, y, a, b[n][n], ans = 0;
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      b[i][j] = 2;
  for (int i=0; i<n; i++) {
    scanf("%d", &a);
    for (int j=0; j<a; j++) {
      scanf("%d %d", &x, &y);
      b[i][x-1] = y;
    }
  }
  for (unsigned int i=0; i<(unsigned int)(1 << n); i++) {
    bool c = false;
    for (int j=0; j<n; j++) {
      for (int k=0; k<n; k++) {
        if (j == k) continue;
        if (b[j][k] == 2) continue;
        if (((i>>j)&1) == 1) {
          if (b[j][k] != ((i>>k)&1)) {
            c = true;
            break;
          }
        }
      }
      if (c) break;
    }
    if (c) continue;
    int cnt = 0;
    for (int j=0; j<n; j++) {if (((i>>j)&1) == 1) cnt++;}
    ans = max(ans, cnt);
  }
  printf("%d\n", ans);
  return 0;
}
