#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
ll p[1001];

int main() {
  int N;
  cin >> N;
  for (int n=2; n<=N; n++) {
    int m = n;
    for (int i=2; i<sqrt((double)m)+0.5; i++) {
      while (m%i == 0) {
        p[i]++;
        m /= i;
      }
    }
    p[m]++;
  }
  ll ans = 1;
  for (int i=2; i<=1000; i++) {
    if (p[i] == 0)
      continue;
    ans *= p[i]+1;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
