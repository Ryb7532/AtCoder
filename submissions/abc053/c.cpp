#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll x;
  cin >> x;
  ll ans = (x-1)/11 * 2;
  if ((x-1)%11<=5)
    ans++;
  else
    ans += 2;
  cout << ans << endl;
  return 0;
}