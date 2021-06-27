#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int W, H;
  cin >> W >> H;
  W /= 4;
  H /= 3;
  if (W == H)
    cout << "4:3" << endl;
  else
    cout << "16:9" << endl;
  return 0;
}
