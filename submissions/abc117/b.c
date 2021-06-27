#include <stdio.h>

int main() {
  int n, l, max = 0, sum = 0;
  scanf("%d", &n);
  for (size_t i = 0; i < n; i++) {
    scanf("%d", &l);
    max = (max < l) ? l : max;
    sum += l;
  }
  if (max < sum - max) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}
