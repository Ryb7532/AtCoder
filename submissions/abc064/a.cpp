#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  if ((10*g+b)%4)
    cout << "NO\n";
  else
    cout << "YES\n";
  return 0;
}
