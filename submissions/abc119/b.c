#include <stdio.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);
  double x[n], ans = 0.0;
  char u[n][4], jpy[4] = "JPY", btc[4] = "BTC";
  for (size_t i = 0; i < n; i++) {
    scanf("%lf%s", x+i, u[i]);
    if (strcmp(u[i], jpy) == 0) {
      ans += x[i];
    } else {
      ans += x[i] * 380000.0;
    }
  }
  printf("%lf\n", ans);
  return 0;
}
