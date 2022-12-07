#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int X, Y;
  cin >> X >> Y;
  if (Y%2 != 0 || Y/2 < X || Y/2 > 2*X)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}
