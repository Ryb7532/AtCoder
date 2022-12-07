#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  char s[10];
  scanf("%s", s);
  if (s[2] == s[3] && s[4] == s[5])
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
