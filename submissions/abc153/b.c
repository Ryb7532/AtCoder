#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int h, n;
  scanf("%d%d", &h, &n);
  int a, sum = 0;
  for (int i=0; i<n; i++) {
    scanf("%d", &a);
    sum += a;
  }
  if (sum >= h) printf("Yes\n");
  else printf("No\n");
  return 0;
}
