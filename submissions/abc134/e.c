#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int a[n], c[n], ans = 0, j = 0, max = -1;
  for (int i=0; i<n; i++) scanf("%d", a+i);
  for (int i=n-1; i>=0; i--) {
    if (a[i]>=max) {
      c[ans++] = a[i];
      max = a[i];
      continue;
    }
    for (j=0; j<ans; j++) {
      if (a[i]<c[j]) {
        c[j] = a[i];
        if (j == ans-1) max = a[i];
        break;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
