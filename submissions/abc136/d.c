#include <stdio.h>
#include <string.h>

int main() {
  char s[100005];
  gets(s);
  int n = strlen(s), ans[n];
  for (size_t i = 0; i < n; i++) {
    ans[i] = 1;
  }
  for (size_t i = 0; i < n-1; i++) {
    if (s[i] == 'R' && s[i+1] == 'R') {
      ans[i+2] += ans[i];
      ans[i] = 0;
    }
  }
  for (size_t i = n-1; i > 0; i--) {
    if (s[i] == 'L' && s[i-1] == 'L') {
      ans[i-2] += ans[i];
      ans[i] = 0;
    }
  }
  for (size_t i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}
