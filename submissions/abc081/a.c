#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  char s[5];
  scanf("%s", s);
  int ans=0;
  for (int i=0; i<3; i++) if (s[i] == '1') ans++;
  printf("%d\n", ans);
  return 0;
}
