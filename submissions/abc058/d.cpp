#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  int n, m;
  cin >> n >> m;
  long x[n], y[m];
  for (int i=0; i<n; i++)
    cin >> x[i];
  for (int i=0; i<m; i++)
    cin >> y[i];
  long sigmax = 0, sigmay = 0, ans;
  for (int i=0; i<n; i++) {
    sigmax += x[i]*(2*i-n+1);
    sigmax %= MOD;
  }
  for (int i=0; i<m; i++) {
    sigmay += y[i]*(2*i-m+1);
    sigmay %= MOD;
  }
  ans = (sigmax*sigmay) % MOD;
  cout << ans << endl;
  return 0;
}