#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define MAX(a, b) ((a>b) ? a : b)
#define MAX3(a, b, c) (MAX(a, MAX(b, c)))

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  int s=MAX3(a, b, c)*3 -a-b-c;
  if (s%2) printf("%d\n", (s+3)/2);
  else printf("%d\n", s/2);
  return 0;
}
