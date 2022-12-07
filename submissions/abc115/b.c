#include <stdio.h>

int main() {
  int n, max = 0, ans = 0;
  scanf("%d", &n);
  int p[n];
  for (size_t i = 0; i < n; i++) {
    scanf("%d", p+i);
    ans += p[i];
    max = (max < p[i]) ? p[i] : max ;
  }
  printf("%d\n", ans - max/2);
  return 0;
}
