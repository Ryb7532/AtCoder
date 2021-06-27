#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 200001 //size of array
const ll MOD = 1e9+7;

ll fac[N], inv[N], finv[N];

void C_init() {
  fac[0] = 1; fac[1] = 1;
  finv[0] = 1; finv[1] = 1;
  inv[1] = 1;
  for (int i=2; i<N; i++){
    fac[i] = fac[i-1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i-1] * inv[i] % MOD;
  }
}

ll C(int a, int b) {
  if (a < b)
    return 0;
  if (a < 0 || b < 0)
    return 0;
  return fac[a] * (finv[b] * finv[a-b] % MOD) % MOD;
}

int main() {
  int W, H;
  cin >> W >> H;
  C_init();
  cout << C(W+H-2, W-1) << endl;
  return 0;
}
