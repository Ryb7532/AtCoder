#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int h1, h2, w1, w2;
  cin >> h1 >> w1 >> h2 >> w2;
  if (h1 != h2 && h1 != w2 && w1 != h2 && w1 && w1 != w2)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
