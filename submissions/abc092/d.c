#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  a--;
  b--;
  char g[100][100];
  for (int i=0; i<50; i++) for (int j=0; j<100; j++) g[i][j] = '#';
  for (int i=50; i<100; i++) for (int j=0; j<100; j++) g[i][j] = '.';
  for (int i=0; i<49; i+=2) {
    if (a==0) break;
    for (int j=0; j<100; j+=2) {
      if (a==0) break;
      g[i][j] = '.';
      a--;
    }
  }
  for (int i=51; i<100; i+=2) {
    if (b==0) break;
    for (int j=0; j<100; j+=2) {
      if (b==0) break;
      g[i][j] = '#';
      b--;
    }
  }
  printf("100 100\n");
  for (int i=0; i<100; i++) {
    for (int j=0; j<100; j++) printf("%c", g[i][j]);
    printf("\n");
  }
  return 0;
}
