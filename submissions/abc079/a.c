#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  char n[5];
  scanf("%s", n);
  if (n[0] == n[1] && n[0] == n[2])
    printf("Yes\n");
  else if (n[1] == n[2] && n[1] == n[3])
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
