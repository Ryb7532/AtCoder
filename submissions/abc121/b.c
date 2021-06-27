#include <stdio.h>

int main() {
  int n, m, c;
  scanf("%d%d%d", &n, &m, &c);
  int b[m], a[n][m], count = 0;
  for (size_t i = 0; i < m; i++) {
    scanf("%d", b+i);
  }
  for (size_t i = 0; i < n; i++) {
    int d = c;
    for (size_t j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
      d += a[i][j] * b[j];
    }
    count += (d > 0) ? 1 : 0;
  }
 printf("%d\n", count);
  return 0;
}
