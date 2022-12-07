#include <stdio.h>

int main() {
  int n, m, k = 0;
  scanf("%d %d", &n, &m);
  int a[m], b[100010];
  for (size_t i = 0; i < m; i++) {
    scanf("%d", a+i);
  }
  b[0] = 0; b[1] = 1;
  for (size_t i = 2; i <= n+1; i++) {
    if (i == a[k]+1) {
      b[i] = 0;
      k++;
    } else {
      b[i] = (b[i-1] + b[i-2]) % 1000000007;
    }
  }
  printf("%d\n", b[n+1]);
  return 0;
}
