#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  int s = 0, m = n;
  while (m != 0) {
    s += m%10;
    m /= 10;
  }
  if (n%s == 0) printf("Yes\n");
  else printf("No\n");
  return 0;
}
