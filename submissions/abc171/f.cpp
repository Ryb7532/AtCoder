#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 2000000 //size of array
const ll MOD = 1e9+7;

ll fac[N], inv[N], finv[N];

void com_init() {
  fac[0] = 1; fac[1] = 1;
  finv[0] = 1; finv[1] = 1;
  inv[1] = 1;
  for (int i=2; i<N; i++){
    fac[i] = fac[i-1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i-1] * inv[i] % MOD;
  }
}

ll combination(int a, int b) {
  if (a < b)
    return 0;
  if (a < 0 || b < 0)
    return 0;
  return fac[a] * (finv[b] * finv[a-b] % MOD) % MOD;
}

int main() {
  int K;
  string S;
  cin >> K >> S;
  int n = S.size();
  ll p = 1, ans = 0;
  com_init();
  for (int i=0; i<K; i++) {
    p *= 25;
    p %= MOD;
  }
  for (int i=0; i<=K; i++) {
    ans += combination(n+K-i-1, n-1) * p % MOD;
    ans %= MOD;
    p *= 26;
    p %= MOD;
    p *= inv[25];
    p %= MOD;
  }
  cout << ans << endl;
  return 0;
}
