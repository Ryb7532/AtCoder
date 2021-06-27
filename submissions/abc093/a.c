#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  char s[4];
  scanf("%s", s);
  bool a=true, b=true, c=true;
  for (int i=0; i<3; i++) {
    if (s[i]=='a') {
      a=false;
    } else if (s[i] == 'b') {
      b=false;
    } else {
      c=false;
    }
  }
  if (a||b||c) printf("No\n");
  else printf("Yes\n");
  return 0;
}
