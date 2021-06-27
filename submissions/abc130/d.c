#include <stdio.h>
#include <limits.h>

long int binarysearch(long int x, int n, long int *a) {
  if (n <= 1) {
    return 0;
  }
  int med = n/2;
  if (a[med-1] < x) {
    return n/2 + binarysearch(x, (n+1)/2, a+med);
  }else {
    return binarysearch(x, n/2, a);
  }
}

int main() {
  int n, a; long int k, ans = 0;
  scanf("%d %ld", &n, &k);
  long int b[n+2];
  b[0] = 0; b[n+1] = LONG_MAX;
  for (size_t i = 0; i < n; i++) {
    scanf("%d", &a);
    b[i+1] = b[i] + a;
  }
  for (size_t i = 0; i < n; i++) {
    ans += n - i - binarysearch(k+b[i], n+1-i, b+1+i);
  }
  printf("%ld\n", ans);
  return 0;
}
