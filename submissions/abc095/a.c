#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  char s[4];
  scanf("%s", s);
  int ans = 700;
  for (int i=0; i<3; i++) {
    if (s[i] == 'o') ans += 100;
  }
  printf("%d\n", ans);
  return 0;
}
