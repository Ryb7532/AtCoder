#include <stdio.h>

int main() {
  int n, k, q;
  scanf("%d%d%d", &n, &k, &q);
  int a[q], b[n];
  for (int i = 0; i < n; i++) {
    b[i] = k-q;
  }
  for (int i=0; i<q; i++) {
    scanf("%d", a+i);
    b[a[i]-1]++;
  }
  for (int i=0; i<n; i++) {
    if (b[i] > 0) {
      printf("Yes\n");
    }else {
      printf("No\n");
    }
  }
  return 0;
}
