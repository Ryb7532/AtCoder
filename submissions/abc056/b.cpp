#include <bits/stdc++.h>
using namespace std;

int main() {
  int W, a, b;
  cin >> W >> a >> b;
  cout << max(0, abs(a-b)-W) << endl;
  return 0;
}
