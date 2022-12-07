#include <stdio.h>

int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  printf("%d\n", (n-1)/(2*d+1)+1);
  return 0;
}
