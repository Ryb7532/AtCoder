#include <stdio.h>

int main() {
  int n, s[30000], ans = 0;
  scanf("%d", &n);
  s[0] = 3; s[1] = 5; s[2] = 7;
  for (size_t i = 1; i < 9841; i++) {
    s[3*i] = s[i-1] * 10 + 3;
    s[3*i+1] = s[i-1] * 10 + 5;
    s[3*i+2] = s[i-1] * 10 + 7;
  }
  for (size_t j = 12; j < 29523; j++) {
    int cn3 = 0, cn5 = 0, cn7 = 0;
    if (s[j] > n) {
      break;
    }
    while (s[j] != 0) {
      s[j] % 10 == 3 ? cn3++ :
      s[j] % 10 == 5 ? cn5++ :
      cn7++;
      s[j] /= 10;
    }
    if (cn3 > 0 && cn5 > 0 && cn7 > 0) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
