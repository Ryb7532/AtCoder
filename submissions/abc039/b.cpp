#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll X;
  cin >> X;
  for (ll i=1; i<1000; i++) {
    if (X == i*i*i*i) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
