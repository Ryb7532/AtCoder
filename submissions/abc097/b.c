#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
#include <math.h>

int main() {
  int x;
  scanf("%d", &x);
  int max = 1;
  for (int i=2; i<=sqrt((double) x); i++) {
    int n = i;
    while (n*i <= x) n *= i;
    max = (max < n) ? n : max;
  }
  printf("%d\n", max);
  return 0;
}
