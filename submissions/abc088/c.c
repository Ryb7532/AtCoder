#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int c[3][3];
  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
      scanf("%d", &c[i][j]);
  int b[3];
  bool judge = true;
  for (int i=0; i<3; i++)
    b[i] = c[0][i] - c[0][0];
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      if (c[i][j] != c[i][0] + b[j]) {
        judge = false;
        break;
      }
    }
  }
  if (judge) printf("Yes\n");
  else printf("No\n");
  return 0;
}
