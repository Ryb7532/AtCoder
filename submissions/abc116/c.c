#include <stdio.h>
#include <limits.h>

int main() {
  int n, m, max = 0, ans = 0;
  scanf("%d", &n);
  int h[n+1];
  h[n] = 0;
  for (size_t i = 0; i < n; i++) {
    scanf("%d", h+i);
    max = (max < h[i]) ? h[i] : max;
  }
  for (size_t j = 0; j < max; j++) {
    m = 0;
    for (size_t i = 0; i < n; i++) {
      if (h[i] != 0 && h[i+1] == 0) {
        m++;
        h[i]--;
      } else if (h[i] != 0 && h[i+1] != 0) {
        h[i]--;
      }
    }
    ans += m;
  }
  printf("%d\n", ans);
  return 0;
}
