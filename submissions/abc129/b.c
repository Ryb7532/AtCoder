#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
  int n;
  scanf("%d", &n);
  int w, sum[n+1], ans = INT_MAX;
  sum[0] = 0;
  for (size_t i = 0; i < n; i++) {
    scanf("%d", &w);
    sum[i+1] = sum[i] + w;
  }
  for (size_t i = 0; i < n+1; i++) {
    int tmp = abs(sum[n] - (2*sum[i]));
    ans = (tmp < ans) ? tmp : ans;
  }
  printf("%d\n", ans);
  return 0;
}
