#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int h[n], cnt = 0, ans = 0;
  scanf("%d", h);
  for (size_t i = 1; i < n; i++) {
    scanf("%d", h+i);
    if (h[i]<=h[i-1]) {
      cnt++;
      ans = (ans < cnt) ? cnt : ans;
    }else {
      cnt = 0;
    }
  }
  printf("%d\n", ans);
  return 0;
}
