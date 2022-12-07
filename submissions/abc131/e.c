#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  if (k>((n-1)*(n-2))/2) {
    printf("-1\n");
    return 0;
  }
  int m=n-1+((n-1)*(n-2))/2-k;
  printf("%d\n", m);
  for (int i=0; i<n-1; i++) printf("1 %d\n", i+2);
  m-=n-1;
  for (int i=1; m>0 && i<n-1; i++) {
    for (int j=i+1; m>0 && j<n; j++) {
      printf("%d %d\n", i+1, j+1);
      m--;
    }
  }
  return 0;
}
