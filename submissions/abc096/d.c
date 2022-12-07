#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <limits.h>
#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  int a[n], i=0, j=2;
  while (i<n && j<=55555) {
    bool boo = true;
    for (int k=2; k<=sqrt((double)j); k++) {
      if (j%k == 0) {
        boo = false;
        break;
      }
    }
    if (boo) {
      a[i] = j;
      i++;
    }
    j+=5;
  }
  for (int i=0; i<n; i++) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
