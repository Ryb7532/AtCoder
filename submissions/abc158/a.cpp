#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  char s[5];
  scanf("%s", s);
  bool c = false;
  for (int i=1; i<3; i++) {
    if (s[0] == s[i])
      continue;
    c = true;
  }
  if (c)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
