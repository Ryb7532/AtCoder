#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  char s[n+1], t[n+1];
  scanf("%s", s);
  scanf("%s", t);
  for (int i=0; i<n; i++) {
    printf("%c", s[i]);
    printf("%c", t[i]);
  }
  printf("\n");
  return 0;
}
