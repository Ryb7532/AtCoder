#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  if (a == b && a != c) printf("Yes\n");
  else if (b == c && b != a) printf("Yes\n");
  else if (c == a && c != b) printf("Yes\n");
  else printf("No\n");
  return 0;
}
