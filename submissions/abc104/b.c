#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
//#include <limits.h>
//#include <math.h>

int main() {
  char s[11];
  scanf("%s", s);
  int l=strlen(s);
  if (s[0] == 'A') {
    int boo = 0;
    for (int i=1; i<l; i++) {
      if (s[i]-'a' >= 0 && s[i]-'a' <26) continue;
      else if (s[i] == 'C' && boo == 0 && i>1 && i<l-1) boo = 1;
      else {
        printf("WA\n");
        return 0;
      }
    }
    if (boo == 1) {
      printf("AC\n");
      return 0;
    }
  }
  printf("WA\n");
  return 0;
}
