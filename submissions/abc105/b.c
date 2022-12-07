#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  for (int i=0; i<=n/4; i++) {
    if ((n-i*4)%7 == 0) {
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
  return 0;
}
