#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  long n, m;
  scanf("%ld%ld", &n, &m);
  long ans;
  if (n==1 && m==1) ans = 1;
  else if (n==1) ans = m-2;
  else if (m==1) ans = n-2;
  else ans = (n-2)*(m-2);
  printf("%ld\n", ans);
  return 0;
}
