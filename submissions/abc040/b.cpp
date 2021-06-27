#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int ans = 1e6;
  for (int i=1; i<=n; i++)
    ans = min(ans, abs(i-n/i)+n%i);
  cout << ans << endl;
  return 0;
}
