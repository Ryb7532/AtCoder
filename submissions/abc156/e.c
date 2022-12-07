#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define Min(a, b) ((a<b) ? a : b)
#define MOD 1000000007
#define N 200001 //size of array

long fac[N], inv[N], finv[N];

void com_init()
{
  fac[0] = 1;
  fac[1] = 1;
  finv[0] = 1;
  finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < N; i++)
  {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

long combination(int a, int b)
{
  if (a < b)
    return 0;
  if (a < 0 || b < 0)
    return 0;
  return fac[a] * (finv[b] * finv[a - b] % MOD) % MOD;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  long ans = 0;
  int l = Min(n-1, k);
  com_init();
  for (int i=0; i<=l; i++) {
    ans += (combination(n, i) * combination(n-1, i))%MOD;
    ans %= MOD;
  }
  printf("%ld\n", ans);
  return 0;
}
