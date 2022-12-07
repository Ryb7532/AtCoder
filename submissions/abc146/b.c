#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  char s[10001];
  scanf("%d", &n);
  scanf("%s", s);
  int l = strlen(s);
  for (int i=0; i<l; i++) {
    if (s[i]-'A'+n < 26) printf("%c", s[i] + n);
    else printf("%c", s[i] + n - 26);
  }
  printf("\n");
  return 0;
}
