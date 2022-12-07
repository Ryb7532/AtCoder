#include <iostream>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans = 0;
  ans = min(b, d) - max(a, c);
  if (ans < 0)
    ans = 0;
  cout << ans;
  return 0;
}
