#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  char s[15], t[15], u[15];
  int a, b;
  scanf("%s %s", s, t);
  scanf("%d%d", &a, &b);
  scanf("%s", u);
  if (strcmp(t, u)) a--;
  else b--;
  printf("%d %d\n", a, b);
  return 0;
}
