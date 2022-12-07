#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  char s[n];
  bool three = true;
  for (int i=0; i<n; i++) {
    scanf("%c", s+i);
    if (s[i] == 'Y') three = false;
  }
  if (three) printf("Three\n");
  else printf("Four\n");
  return 0;
}
