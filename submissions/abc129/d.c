#include <stdio.h>

int main() {
  int h, w;
  scanf("%d%d", &h, &w);
  char s[2001][2001]; int r[h][w], l[h][w], u[h][w], d[h][w], max = 0;
  for (int i=0; i<h; i++) scanf("%s", s[i]);
  for (int i=0; i<h; i++) {
    r[i][w-1] = (s[i][w-1] == '.') ? 1 : 0;
    l[i][0] = (s[i][0] == '.') ? 1 : 0;
  }
  for (int i=0; i<w; i++) {
    u[0][i] = (s[0][i] == '.') ? 1 : 0;
    d[h-1][i] = (s[h-1][i] == '.') ? 1 : 0;
  }
  for (int i=0; i<h; i++) {
    for (int j=1; j<w; j++) {
      if(s[i][j] == '.') l[i][j] = l[i][j-1]+1;
      else l[i][j] = 0;
      if(s[i][w-j-1] == '.') r[i][w-j-1] = r[i][w-j]+1;
      else r[i][w-j-1] = 0;
    }
  }
  for (int j=0; j<w; j++) {
    for (int i=1; i<h; i++) {
      if(s[i][j] == '.') u[i][j] = u[i-1][j]+1;
      else u[i][j] = 0;
      if(s[h-i-1][j] == '.') d[h-i-1][j] = d[h-i][j]+1;
      else d[h-i-1][j] = 0;
    }
  }
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      int sum = u[i][j] + d[i][j] + l[i][j] + r[i][j];
      max = (sum > max) ? sum : max;
    }
  }
  if (max != 0) max -= 3;
  printf("%d\n", max);
  return 0;
}
