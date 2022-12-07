#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int h, w;
  scanf("%d%d", &h, &w);
  char g[h+2][w+2];
  for (int i=0; i<h+2; i++) g[i][0] ='.';
  for (int i=0; i<w+2; i++) {
    g[0][i] = '.';
    g[h+1][i] = '.';
  }
  for (int i=0; i<h; i++) {
    scanf("%s", g[i+1]);
  }
  for (int i=1; i<h+1; i++) {
    for (int j=1; j<w+1; j++) {
      if (g[i][j] != '#') continue;
      if (g[i][j-1] != '#' && g[i][j+1] != '#' && g[i-1][j] != '#' && g[i+1][j] != '#') {
        printf("No\n");
        return 0;
      }
    }
  }
  printf("Yes\n");
  return 0;
}
