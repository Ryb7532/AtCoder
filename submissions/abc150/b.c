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
  int ans = 0;
  for (int i=0; i<n-2; i++) {
    if (s[i] == 'A') {
      if (s[i+1] == 'B') {
        if (s[i+2] == 'C') {
          ans++;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
