#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <limits.h>
#include <math.h>

#define MOD 1000000007
#define N 1000001 //size of array
#define max(a, b) (a > b ? a : b)

long inv[N];

void com_init()
{
  inv[1] = 1;
  for (int i = 2; i < N; i++)
  {
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int a[n], p[N] = {0};
  long ans = 0, b = 1;
  for (int i=0; i<n; i++) {
    scanf("%d", a+i);
    int j, m = a[i];
    for (j = 2; j <= sqrt((double)m)+1; j++)
    {
      if (m == 1)
        break;
      if (m % j != 0)
        continue;
      int cnt = 0;
      while (m % j == 0)
      {
        m /= j;
        cnt++;
      }
      p[j] = max(cnt, p[j]);
    }
    if (m != 1) {
      p[m] = max(1, p[m]);
    }
  }
  for (int i=2; i<N; i++) {
    int j = p[i];
    while (j != 0) {
      b *= i;
      b %= MOD;
      j--;
    }
  }
  com_init();
  for (int i=0; i<n; i++) {
    ans += (b * inv[a[i]]) % MOD;
    ans %= MOD;
  }
  printf("%ld\n", ans);
  return 0;
}
