#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  char s[101];
  scanf("%s", s);
  int n = strlen(s), ans = 0;
  for (int i=0; i<n/2; i++) {
    if (s[i] == s[n-1-i]) continue;
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}
