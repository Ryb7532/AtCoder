#include <stdio.h>

int main() {
  int n, cnt = 0;
  scanf("%d", &n);
  int a[n], b[n+1];
  for (size_t i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  for (size_t i = n; i > 0; i--) {
    int c = n/i, d = 0;
    if (c>1) {
      for (size_t j = 1; j < c; j++) {
        d += b[(j+1)*i];
      }
    }
    if (a[i-1] == d%2) {
      b[i] = 0;
    }else {
      b[i] = 1;
      cnt++;
    }
  }
  printf("%d\n", cnt);
  for (size_t i = 0; i < n; i++) {
    if (b[i+1] == 1) {
      printf("%d ", i+1);
    }
  }
  printf("\n");
  return 0;
}
