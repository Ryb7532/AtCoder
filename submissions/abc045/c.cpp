#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  int n = S.size();
  ll ans = 0;
  for (int i=0; i<(1<<(n-1)); i++) {
    ll a = 0;
    for (int j=0; j<n-1; j++) {
      a += S[j] - '0';
      if (i & (1<<j)) {
        ans += a;
        a = 0;
      }
      a *= 10;
    }
    ans += a + S[n-1] - '0';
  }
  cout << ans << endl;
  return 0;
}