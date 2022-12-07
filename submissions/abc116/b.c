#include <stdio.h>

int main() {
  int j, i, a[1000000];
  scanf("%d", a);
  for (j = 1; j > 0; j++) {
    a[j] = (a[j-1] % 2 == 0) ? a[j-1] / 2 : 3*a[j-1] + 1;
    for (size_t k = 0; k < j; k++) {
      if (a[k] == a[j]) {
        i = k;
        break;
      }
    }
    if (a[i] == a[j]) {
      break;
    }
  }
  printf("%d\n", j+1);
  return 0;
}
