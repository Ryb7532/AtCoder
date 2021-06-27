#include <bits/stdc++.h>
using namespace std;

int main() {
  long X, m = 100;
  cin >> X;
  int cnt = 0;
  while (X>m) {
    m += m/100;
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}
