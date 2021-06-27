#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int h, w;
  scanf("%d%d", &h, &w);
  char s[h+2][w+5];
  for (int i=0; i<w; i++) {
    s[0][i] = '.';
    s[h+1][i] = '.';
  }
  for (int i=0; i<h; i++)
    scanf("%s", s[i+1]);
  for (int i=0; i<h+2; i++)
    s[i][w] = '.';
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (s[i+1][j] == '#')
        continue;
      int cnt = 0;
      if (j != 0) {
        if (s[i][j-1] == '#')
          cnt++;
        if (s[i+1][j-1] == '#')
          cnt++;
        if (s[i+2][j-1] == '#')
          cnt++;
      }
      if (s[i][j] == '#')
        cnt++;
      if (s[i][j+1] == '#')
        cnt++;
      if (s[i+1][j+1] == '#')
        cnt++;
      if (s[i+2][j] == '#')
        cnt++;
      if (s[i+2][j+1] == '#')
        cnt++;
      s[i+1][j] = cnt+'0';
    }
  }
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++)
      printf("%c", s[i+1][j]);
    printf("\n");
  }
  return 0;
}
