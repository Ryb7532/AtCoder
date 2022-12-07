#include <stdio.h>
#include <string.h>

int main() {
  char s[100001];
  scanf("%s", s);
  int n = strlen(s), r=0, b=0;
  for (size_t i = 0; i < n; i++) {
    if (s[i] == '0') {
      r++;
    } else {
      b++;
    }
  }
  if (r > b) {
    printf("%d\n", n + b - r);
  } else {
    printf("%d\n", n + r - b);
  }
  return 0;
}
