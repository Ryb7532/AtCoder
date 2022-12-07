#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
//#include <limits.h>
//#include <math.h>

int main() {
  char s[101], t[101];
  scanf("%s%s", s, t);
  int n = strlen(s);
  for (int i=0; i<n; i++) {
    int j=0;
    while (s[(j+i)%n] == t[j] && j<n) j++;
    if (j==n) {
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
  return 0;
}
