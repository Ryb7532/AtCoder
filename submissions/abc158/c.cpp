#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  int ans = -1;
  for (int i=0; i<=1000; i++) {
    if ((i*8)/100 == a && (i*10)/100 == b) {
      ans = i;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}
