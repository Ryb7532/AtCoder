#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <limits.h>
//#include <math.h>

int main() {
  char s[5];
  scanf("%s", s);
  int ans = 0;
  for (int i=0; i<4; i++) {
    if (s[i] == '+') ans++;
    else if (s[i] == '-') ans--;
  }
  printf("%d\n", ans);
  return 0;
}
