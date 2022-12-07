#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int h[n];
  for (size_t i = 0; i < n; i++) {
    scanf("%d", h+i);
  }
  for (size_t i = n-1; i > 0; i--) {
    if (h[i-1]-h[i] == 1) {
      h[i-1]--;
    }else if (h[i-1]-h[i] > 1) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}
