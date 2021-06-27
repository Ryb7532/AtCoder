#include <stdio.h>

int main() {
  char s[5];
  gets(s);
  if ((s[0] == s[1] && s[2] == s[3] && s[0] != s[2]) ||
  (s[0] == s[2] && s[1] == s[3] && s[0] != s[1]) ||
  (s[0] == s[3] && s[1] == s[2] && s[0] != s[1])) {
    printf("Yes\n");
    return 0;
  }
  printf("No\n");
  return 0;
}
