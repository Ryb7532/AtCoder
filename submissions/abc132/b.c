#include <stdio.h>

int main() {
  int n, ans = 0;
  scanf("%d", &n);
  int p[n];
  for (size_t i = 0; i < n; i++) {
    scanf("%d", p+i);
  }
  for (size_t i = 1; i < n-1; i++) {
    if ((p[i-1] < p[i] && p[i] < p[i+1]) ||
        (p[i-1] > p[i] && p[i] > p[i+1])) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
