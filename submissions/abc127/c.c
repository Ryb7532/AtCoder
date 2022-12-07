#include <stdio.h>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int l, r, min = 1, max = n;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &l, &r);
    if (min < l) {
      min = l;
    }
    if (max > r) {
      max = r;
    }
  }
  int ans = max - min + 1;
  if (ans < 0) {
    ans = 0;
  }
  printf("%d\n", ans);
  return 0;
}
