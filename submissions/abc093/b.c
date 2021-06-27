#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int a, b, k;
  scanf("%d%d%d", &a, &b, &k);
  if (b-a+1 > 2*k) {
    for (int i=0; i<k; i++) printf("%d\n", a+i);
    for (int i=k-1; i>=0; i--) printf("%d\n", b-i);
  } else {
    for (int i=a; i<=b; i++) printf("%d\n", i);
  }
  return 0;
}
