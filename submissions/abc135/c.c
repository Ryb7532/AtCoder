#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int a[n+1], b[n]; long int ans = 0;
  for (size_t i = 0; i < n+1; i++) {
    scanf("%d", a+i);
  }
  for (size_t i = 0; i < n; i++) {
    scanf("%d", b+i);
  }
  for (size_t i = 0; i < n; i++) {
    if (a[i] <= b[i]) {
      ans += a[i];
      b[i] -= a[i];
      if (a[i+1] <= b[i]) {
        ans += a[i+1];
        a[i+1] = 0;
      }else {
        ans += b[i];
        a[i+1] -= b[i];
      }
    }else {
      ans += b[i];
    }
  }
  printf("%ld\n", ans);
  return 0;
}
