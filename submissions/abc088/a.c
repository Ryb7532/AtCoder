#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n, a;
  scanf("%d", &n);
  scanf("%d", &a);
  if (n%500 <= a) printf("Yes\n");
  else printf("No\n");
  return 0;
}
