#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define MAX_N 200001 //size of array

long fac[MAX_N], inv[MAX_N], finv[MAX_N];

void com_init()
{
  fac[0] = 1;
  fac[1] = 1;
  finv[0] = 1;
  finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX_N; i++)
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
  int N, M, K;
  cin >> N >> M >> K;
  long c = M;
  for (int i=0; i<N-K-1; i++) {
    c *= M-1;
    c %= MOD;
  }
  com_init();
  long ans = 0;
  for (int i=K; i>=0; i--) {
    ans += (c*combination(N-1, i)) % MOD;
    ans %= MOD;
    c *= M-1;
    c %= MOD;
  }
  cout << ans << endl;
  return 0;
}
