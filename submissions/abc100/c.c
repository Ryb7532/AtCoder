#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  int a[n], cnt = 0;
  for (int i=0; i<n; i++) {
    scanf("%d", a+i);
    while (a[i]%2 == 0) {
      a[i] /= 2;
      cnt++;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
