#include <stdio.h>

int main() {
  int h, w;
  scanf("%d%d", &h, &w);
  char g[h][w+1];
  for (int i=0; i<h; i++) scanf("%s", g[i]);
  for (int i=0; i<h; i++) {
    int j=0;
    while (g[i][j] == '.' && j<w) j++;
    if (j==w) {
      for (int j=0; j<w; j++) g[i][j] = '0';
    }
  }
  for (int i=0; i<w; i++) {
    int j=0;
    while (g[j][i] != '#' && j<h) j++;
    if (j==h) {
      for (int j=0; j<h; j++) g[j][i] = '0';
    }
  }
  for (int i=0; i<h; i++) {
    int boo = 0;
    for (int j=0; j<w; j++) {
      if (g[i][j] != '0') {
        printf("%c", g[i][j]);
        boo = 1;
      }
    }
    if (boo) printf("\n");
  }
  return 0;
}
