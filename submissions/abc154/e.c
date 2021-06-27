#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  char n[105];
  int k;
  scanf("%s %d", n, &k);
  int len = strlen(n);
  int dp1[len][3], dp2[len][3];
  dp1[0][0] = n[len-1]-'0';
  dp2[0][0] = 9-dp1[0][0];
  dp1[0][1] = 0;
  dp2[0][1] = 0;
  dp1[0][2] = 0;
  dp2[0][2] = 0;
  for (int i=1; i<len; i++) {
    int a = n[len-i-1]-'0';
    if (a == 0) {
      dp1[i][0] = dp1[i-1][0];
      dp2[i][0] = dp2[i-1][0] + 9;
    } else {
      dp1[i][0] = a + dp1[i-1][0] + dp2[i-1][0];
      dp2[i][0] = 9 - a;
    }
    for (int j=1; j<3; j++) {
      if (a == 0) {
        dp1[i][j] = dp1[i-1][j];
        dp2[i][j] = dp2[i-1][j] + 9*(dp1[i-1][j-1] + dp2[i-1][j-1]);
      } else {
        dp1[i][j] = dp1[i-1][j] + dp2[i-1][j] + (a-1)*(dp1[i-1][j-1]+dp2[i-1][j-1]) + dp1[i-1][j-1];
        dp2[i][j] = (9-a)*(dp1[i-1][j-1]+dp2[i-1][j-1]) + dp2[i-1][j-1];
      }
    }
  }
  printf("%d\n", dp1[len-1][k-1]);
  return 0;
}
