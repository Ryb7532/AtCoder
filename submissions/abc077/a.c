#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  char c[2][5];
  scanf("%s", c[0]);
  scanf("%s", c[1]);
  bool check = true;
  for (int i=0; i<3; i++) {
    if (c[0][i] != c[1][2-i])
      check = false;
  }
  if (check)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
