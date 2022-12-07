#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  if (a<b) {
    for (int i=0; i<b; i++) printf("%d", a);
    printf("\n");
  } else {
    for (int i=0; i<a; i++) printf("%d", b);
    printf("\n");
  }
  return 0;
}
