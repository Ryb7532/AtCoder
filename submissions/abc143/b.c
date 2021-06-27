#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int d[n], ans=0;
  for (int i=0; i<n; i++) scanf("%d", d+i);
  for (int i=0; i<n-1; i++) {
    for (int j=i+1; j<n; j++) {
      ans += d[i]*d[j];
    }
  }
  printf("%d\n", ans);
  return 0;
}
