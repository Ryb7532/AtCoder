#include <stdio.h>

int main() {
  int n, ans;
  scanf("%d", &n);
  ans = (n-1)/111+1;
  printf("%d\n", ans*111);
  return 0;
}
