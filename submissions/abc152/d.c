#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  int a[9][10] = {0}, ans = 0;
  for (int i=1; i<=n; i++) {
    int b = i;
    while (b%10 != b) b /= 10;
    a[b-1][i%10]++;
  }
  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) {
      ans += a[i][j+1] * a[j][i+1];
    }
  }
  printf("%d\n", ans);
  return 0;
}
