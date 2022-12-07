#include <stdio.h>
#include <limits.h>

int binarysearch(int x, int n, int *a) {
  if (n <= 1) {
    return 1;
  }
  int tmp = n/2;
  if(a[tmp] <= x) {
    return tmp + binarysearch(x, (n+1)/2, a+tmp);
  } else {
    return binarysearch(x, n/2, a);
  }
}

int main() {
  int n, x, ans;
  scanf("%d%d", &n, &x);
  int l, d[n+2];
  d[0] = 0;
  d[n+1] = INT_MAX;
  for (size_t i = 0; i < n; i++) {
    scanf("%d", &l);
    d[i+1] = d[i] + l;
  }
  ans = binarysearch(x, n+2, d);
  printf("%d\n", ans);
  return 0;
}
