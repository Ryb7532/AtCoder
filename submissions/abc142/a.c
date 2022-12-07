#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  double ans = (double)((n+1)/2)/n;
  printf("%.10lf\n", ans);
  return 0;
}
