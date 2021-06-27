#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  long l[87];
  l[0] = 2;
  l[1] = 1;
  for (int i=2; i<n+1; i++)
    l[i] = l[i-1] + l[i-2];
  printf("%ld\n", l[n]);
  return 0;
}
