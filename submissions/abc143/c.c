#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  char s[n+1];
  scanf("%s", s);
  int ans = 1; char c = s[0];
  for (int i=1; i<n; i++) {
    if (c == s[i]) continue;
    ans++;
    c=s[i];
  }
  printf("%d\n", ans);
  return 0;
}
