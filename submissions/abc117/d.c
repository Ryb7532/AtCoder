#include <stdio.h>
//WA
int main() {
  int n, m;
  long int k, l = 0, ans = 0;
  scanf("%d%ld", &n, &k);
  long int a[n], b[n];
  int count[40];
  for (size_t i = 0; i < n; i++) {
    scanf("%ld", a+i);
    b[i] = a[i];
  }
  for (size_t i = 0; i < 40; i++) {
    count[i] = 0;
    for (size_t j = 0; j < n; j++) {
      count[i] += a[j] % 2;
      a[j] = a[j]/2;
    }
  }
  for (m = 40; m > 0; m--) {
    if ((k & (1ull<<(m-1))) != 0) {
      break;
    }
  }
  while (m > 0) {
    if (count[m-1] < (n+1)/2 && l + (1ull<<(m-1)) <= k) {
      l += (1ull<<(m-1));
    }
    m--;
  }
  for (size_t i = 0; i < n; i++) {
    ans += b[i] ^ l;
  }
  printf("%ld\n", ans);
  return 0;
}
