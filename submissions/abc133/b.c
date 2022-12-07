#include <stdio.h>
#include <math.h>

int main() {
  int n, d, ans = 0;
  scanf("%d%d", &n, &d);
  int x[n][d];
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < d; j++) {
      scanf("%d", &x[i][j]);
    }
  }
  for (size_t i = 0; i < n-1; i++) {
    for (size_t j = i+1; j < n; j++) {
      int a = 0;
      for (size_t k = 0; k < d; k++) {
        a += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
      }
      for (size_t k = 1; k <= a; k++) {
        if (a == k*k) {
          ans++;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
