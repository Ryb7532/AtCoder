#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ans = 0;
  if (a != b)
    ans++;
  if (b != c)
    ans++;
  if (c != a)
    ans++;
  if (ans == 0)
    ans++;
  cout << ans << endl;
  return 0;
}
