#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  if (A%3 == 0 || B%3 == 0 || (A+B)%3 == 0)
    cout << "Possible\n";
  else
    cout << "Impossible\n";
  return 0;
}
