#include <stdio.h>

int main() {
  char s[10], t[10];
  scanf("%s\n", s);
  scanf("%s", t);
  int ans = 0;
  for (size_t i = 0; i < 3; i++) {
    ans = (s[i] == t[i]) ? ans+1 : ans;
  }
  printf("%d\n", ans);
  return 0;
}
