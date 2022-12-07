#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define Min(a, b) ((a < b) ? a : b)

int main() {
  int n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  x--;
  y--;
  int ans[n-1];
  for (int i=0; i<n; i++)
    ans[i] = 0;
  for (int i=0; i<n-1; i++) {
    for (int j=i+1; j<n; j++) {
      if (i<x) {
        if (j<x)
          ans[j-i]++;
        else if (j>=y)
          ans[x-i+j-y+1]++;
        else
          ans[x-i+Min(j-x, y-j+1)]++;
      } else if (i>=y) {
        ans[j-i]++;
      } else {
        if (j>=y) {
          ans[j-y+Min(i-x+1, y-i)]++;
        } else {
          ans[Min(j-i, y-j+i-x+1)]++;
        }
      }
    }
  }
  for (int i=1; i<n; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
