#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int p[n], cnt = 0;
  for (size_t i = 0; i < n; i++) {
    scanf("%d", p+i);
  }
  for (size_t i = 0; i < n; i++) {
    if (p[i] != i+1) {
      cnt++;
    }
  }
  if (cnt <= 2) {
    printf("YES\n");
  }else {
    printf("NO\n");
  }
  return 0;
}
