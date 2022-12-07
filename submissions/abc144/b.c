#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  for (int i=1; i<10; i++) {
    for (int j=1; j<10; j++) {
      if (n == i*j) {
        printf("Yes\n");
        return 0;
      }
    }
  }
  printf("No\n");
  return 0;
}
