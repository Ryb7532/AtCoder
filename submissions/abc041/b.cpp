#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main() {
  ll A, B, C;
  cin >> A >> B >> C;
  cout << ((A*B)%MOD *C)%MOD << endl;
  return 0;
}
