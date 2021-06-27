#include <stdio.h>

int main() {
  int n, m, k, t, count = 0;
  scanf("%d%d", &n, &m);
  int l[m];
  for (size_t i = 0; i < m; i++) {
    l[i] = 0;
  }
  for (size_t i = 0; i < n; i++) {
    scanf("%d", &k);
    for (size_t j = 0; j < k; j++) {
      scanf("%d", &t);
      l[t-1]++;
    }
  }
  for (size_t i = 0; i < m; i++) {
    if (l[i] == n) {
      count++;
    }
  }
  printf("%d\n", count);
  return 0;
}
