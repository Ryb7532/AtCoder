#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  char s[3][4];
  for (int i=0; i<3; i++) scanf("%s", s[i]);
  printf("%c%c%c\n", s[0][0], s[1][1], s[2][2]);
  return 0;
}
