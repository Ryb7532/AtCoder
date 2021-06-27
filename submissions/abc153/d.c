#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

long ans(long h) {
  if (h == 1) return 1;
  else return 2*ans(h/2) + 1;
}

int main() {
  long h;
  scanf("%ld", &h);
  printf("%ld\n", ans(h));
  return 0;
}
