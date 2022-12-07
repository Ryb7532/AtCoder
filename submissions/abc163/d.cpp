#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  long n, k;
  cin >> n >> k;
  long ans = 1, sigma = n*(n+1)/2;
  for (long i=k; i<=n; i++) {
    ans += sigma - (n-i)*(n-i+1)/2 - (i-1)*i/2 + 1;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
