#include <stdio.h>

int main() {
  int a[5], k = 0, min = 10, ans = 0;
  scanf("%d", a);
  scanf("%d", a+1);
  scanf("%d", a+2);
  scanf("%d", a+3);
  scanf("%d", a+4);
  for (int i = 0; i < 5; i++) {
    int f = (a[i]-1)%10 + 1;
    if (f < min) {
      min = f;
      k = i;
    }
  }
  for (int i = 0; i < 5; i++) {
    if (i == k) {
      ans += a[i];
    }else {
      ans += (((a[i] - 1) / 10) + 1) * 10;
    }
  }
  printf("%d\n", ans);
  return 0;
}
