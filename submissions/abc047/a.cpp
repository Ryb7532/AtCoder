#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a+b == c || a+c == b || b+c == a)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
