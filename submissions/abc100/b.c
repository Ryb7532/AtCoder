#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int d, n;
  scanf("%d%d", &d, &n);
  int ans;
  ans = n;
  if (ans == 100) ans++;
  for (int i=0; i<d; i++) ans *= 100;
  printf("%d\n", ans);
  return 0;
}
