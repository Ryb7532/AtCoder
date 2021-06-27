#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  int a[n], j=1;
  for (int i=0; i<n; i++)
    scanf("%d", a+i);
  for (int i=0; i<n; i++) {
    if (a[i] == j) j++;
  }
  if (j == 1) {
    printf("-1\n");
    return 0;
  }
  printf("%d\n", n-j+1);
  return 0;
}
