#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
  int n;
  scanf("%d", &n);
  int a[n], count = 0, min = INT_MAX, k = 0;
  long int ans = 0;
  for (size_t i = 0; i < n; i++) {
    scanf("%d", a+i);
    if (a[i] < 0) {
      count++;
      a[i] = abs(a[i]);
    }
    if (a[i] < min) {
      k = i;
      min = a[i];
    }
  }
  if (count % 2 == 0) {
    for (size_t i = 0; i < n; i++) {
      ans += a[i];
    }
  } else {
    for (size_t i = 0; i < n; i++) {
      if (i != k) {
        ans += a[i];
      } else {
        ans -= a[i];
      }
    }
  }
  printf("%ld\n", ans);
  return 0;
}
