#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  char s[5];
  scanf("%s", s);
  int n[4];
  char ans[3];
  for (int i=0; i<4; i++)
    n[i] = s[i] - '0';
  for (int i=0; i<(1<<3); i++) {
    int res = n[0];
    for (int j=0; j<3; j++) {
      if (i & (1<<j)) {
        res -= n[j+1];
        ans[j] = '-';
      } else {
        res += n[j+1];
        ans[j] = '+';
      }
    }
    if (res == 7)
      break;
  }
  printf("%d%c%d%c%d%c%d=7\n", n[0], ans[0], n[1], ans[1], n[2], ans[2], n[3]);
  return 0;
}
