#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll a, b, x, ans;
  cin >> a >> b >> x;
  if (a == 0)
    ans = b/x+1;
  else
    ans = b/x - (a-1)/x;
  cout << ans << endl;;
  return 0;
}
