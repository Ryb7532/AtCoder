#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int a[n]; long int ans[n];
  ans[0] = 0;
  for (size_t i = 0; i < n; i++) {
    scanf("%d", a+i);
    ans[0] = (i%2 == 0) ? ans[0]+a[i] : ans[0]-a[i];
  }
  printf("%ld", ans[0]);
  for (size_t i = 1; i < n; i++) {
    ans[i] = a[i-1]*2-ans[i-1];
    printf(" %ld", ans[i]);
  }
  return 0;
}
