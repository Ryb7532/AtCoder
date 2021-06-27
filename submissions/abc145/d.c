#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define MOD 1000000007
#define N 1000001
#define MIN(a, b) ((a<b) ? a : b)

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
  int x, y;
  scanf("%d%d", &x, &y);
  if ((x+y)%3 == 0) {
    int a = x - (x+y)/3, b = y - (x+y)/3;
    com_init();
    printf("%ld\n", combination(a+b, MIN(a, b)));
    return 0;
  }
  printf("0\n");
  return 0;
}
