#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, x;
  cin >> n >> x;
  cout << min(n-x, x-1) << endl;
  return 0;
}
