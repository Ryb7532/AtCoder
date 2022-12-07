#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ans = a+b+c-max(a, max(b,c));
  cout << ans << endl;
  return 0;
}
