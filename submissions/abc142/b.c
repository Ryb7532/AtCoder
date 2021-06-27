#include <stdio.h>

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int h, ans=0;
  for (int i=0; i<n; i++) {
    scanf("%d", &h);
    ans = (h>=k) ? ans+1 : ans;
  }
  printf("%d\n", ans);
  return 0;
}
