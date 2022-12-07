#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(a, b) ((a<b) ? a : b)

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int a, x[n+1], p=-1;
  for (int i=0; i<n; i++) {
    scanf("%d", &a);
    if (a>=0) {
      x[i+1] = a;
      if (p==-1) {
        x[i] = 0;
        p=i;
      }
    } else {
      x[i] = a;
    }
  }
  if (p==-1) {
    x[n] = 0;
    p=n;
  }
  long right[n+1], ans = LONG_MAX;
  for (int i=0; i<n+1; i++) {
    if (p+i<=n && p-k+i>=0) {
      right[i] = MIN(abs(x[p+i]) + abs(x[p+i]-x[p-k+i]), abs(x[p-k+i]) + abs(x[p-k+i]-x[p+i]));
    } else right[i] = LONG_MAX;
  }
  for (int i=0; i<n+1; i++) ans = MIN(ans, right[i]);
  printf("%ld\n", ans);
  return 0;
}
