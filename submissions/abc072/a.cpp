#include <iostream>
using namespace std;

int main() {
  int x, t;
  cin >> x >> t;
  int ans = (x>t) ? x-t : 0;
  cout << ans << '\n';
  return 0;
}
