#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define MOD 1000000007
#define N 100005

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

int acs(const void *a, const void *b)
{
  return *(long *)a - *(long *)b;
}

int main() {
  int n, k;
  scanf("%d %d", &n ,&k);
  long a[n], ans=0;
  for (int i=0; i<n; i++) scanf("%ld", a+i);
  qsort(a, n, sizeof(long), acs);
  com_init();
  for (int i=0; i<n-k+1; i++) {
    ans -= (a[i]*combination(n-i-1, k-1))%MOD;
    ans %= MOD;
  }
  for (int i=k-1; i<n; i++) {
    ans += (a[i]*combination(i, k-1))%MOD;
    ans %= MOD;
  }
  if (ans < 0) ans += MOD;
  printf("%ld\n", ans);
  return 0;
}
