#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  char s[a+b+5];
  scanf("%s", s);
  bool check = true;
  for (int i=0; i<a+b+1; i++) {
    if (i == a) {
      if (s[i] == '-')
        continue;
    } else {
      if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
        continue;
    }
    check = false;
    break;
  }
  if (check) printf("Yes\n");
  else printf("No\n");
  return 0;
}
