#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  char x, y;
  scanf("%c %c", &x, &y);
  if (x-y>0)
    printf(">");
  else if (x-y<0)
    printf("<");
  else
    printf("=");
  return 0;
}
