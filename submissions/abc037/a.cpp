#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  cout << C/min(A, B) << endl;
  return 0;
}
