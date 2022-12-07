#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int x, sum = 0;
  for (int i=0; i<5; i++) {
    cin >> x;
    sum += x;
  }
  cout << 15-sum << endl;;
  return 0;
}
