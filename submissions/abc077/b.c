#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
#include <math.h>

int main() {
  int n, ans;
  scanf("%d", &n);
  ans = (int)sqrt((double)n);
  printf("%d\n", ans*ans);
  return 0;
}
