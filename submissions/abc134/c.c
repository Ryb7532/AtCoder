#include <stdio.h>

int main() {
  int n, max = 0, smax = 0, maxi;
  scanf("%d", &n);
  int a[n];
  for (size_t i = 0; i < n; i++) {
    scanf("%d", a+i);
    if (max<a[i]) {
      smax = max;
      max = a[i];
      maxi = i;
    }else if (smax<a[i]) {
      smax = a[i];
    }
  }
  for (size_t i = 0; i < n; i++) {
    if (i == maxi) {
      printf("%d\n", smax);
    }else {
      printf("%d\n", max);
    }
  }
  return 0;
}
