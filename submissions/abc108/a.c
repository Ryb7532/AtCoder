#include <stdio.h>

int main() {
  int k;
  scanf("%d", &k);
  int even = k/2, odd = (k%2 == 1) ? even+1 : even;
  printf("%d\n", even*odd);
  return 0;
}
