#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define MOD 1000000007

int main() {
  int n;
  scanf("%d", &n);
  long long a[n], ans = 0, cnt0[60] = {0}, cnt1[60] = {0};
  for (int i=0; i<n; i++) {
    scanf("%lld", a+i);
    for (int j=0; j<60; j++)
      if ((a[i]&(1ull<<j)) == 0) cnt0[j]++;
      else cnt1[j]++;
  }
  for (int i=0; i<60; i++) {
    ans += (((cnt1[i] * (cnt0[i])) % MOD) * ((1ull << i) % MOD)) % MOD;
    ans %= MOD;
  }
  printf("%lld\n", ans);
  return 0;
}
