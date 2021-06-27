#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  char s[101], t[201];
  scanf("%s %s", s, t);
  strcat(t, s);
  int n = strlen(t);
  for (int i=0; i<n; i++) printf("%c", t[i]);
  printf("\n");
  return 0;
}
