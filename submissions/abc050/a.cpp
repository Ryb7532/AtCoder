#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int A, B;
  string op;
  cin >> A >> op >> B;
  if (op[0] == '+')
    cout << A+B << endl;
  else
    cout << A-B << endl;
  return 0;
}
