#include <stdio.h>
#include <string.h>

int main() {
  char s[105];
  gets(s);
  int n = strlen(s);
  for (int i = 0; i < n; i++) {
    if (i%2==0) {
      if (s[i] == 'R' || s[i] == 'U' || s[i] == 'D') continue;

      printf("No\n");
      return 0;
    }else {
      if (s[i] == 'L' || s[i] == 'U' || s[i] == 'D') continue;

      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}
