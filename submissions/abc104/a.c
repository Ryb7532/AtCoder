#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int r;
  scanf("%d", &r);
  if (r<1200) printf("ABC\n");
  else if (r<2800) printf("ARC\n");
  else printf("AGC\n");
  return 0;
}
