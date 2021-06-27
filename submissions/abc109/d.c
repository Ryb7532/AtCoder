#include <stdio.h>

int main() {
  int h, w;
  scanf("%d%d\n", &h, &w);
  int g[h][w], m[h][w], cnt = 0;
  for (int i=0; i<h; i++) for (int j=0; j<w; j++) m[i][j] = 0;
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      scanf("%d", g[i]+j);
      if ((g[i][j]+m[i][j])%2) {
        if (j!=w-1) {
          m[i][j+1]++;
          cnt++;
        }
        else if (i!=h-1) {
          m[i+1][j]++;
          cnt++;
        }
      }
    }
  }
  printf("%d\n", cnt);
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (g[i][j]%2 == 0) continue;
      if (j != w-1) {
        g[i][j+1]++;
        printf("%d %d %d %d\n", i+1, j+1, i+1, j+2);
      } else if (i != h-1){
        g[i+1][j]++;
        printf("%d %d %d %d\n", i+1, j+1, i+2, j+1);
      }
    }
  }
  return 0;
}
