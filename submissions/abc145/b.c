#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n;
  scanf("%d", &n);
  char s[n+1];
  scanf("%s", s);
  if (n%2 == 1) {
    printf("No\n");
    return 0;
  }
  for (int i=0; i<n/2; i++) {
    if (s[i] != s[i+n/2]) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}
