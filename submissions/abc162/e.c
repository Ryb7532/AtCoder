#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define MOD 1000000007

long powlong(long a, int b) {
  long res = 1;
  if (a == 1)
    return 1;
  for (; b>0; b>>=1, a=(a*a)%MOD) {
    if (b%2) {
      res *= a;
      res %= MOD;
    }
  }
  return res;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  long a[k], ans = 0;
  for (int i=k-1; i>=0; i--) {
    a[i] = powlong(k/(i+1), n);
    for (int j=2*i+1; j<k; j+=i+1) {
      a[i] -= a[j];
      a[i] %= MOD;
    }
  }
  for (int i=0; i<k; i++) {
    ans += ((i+1)*a[i])%MOD;
    ans %= MOD;
  }
  printf("%ld\n", ans);
  return 0;
}
