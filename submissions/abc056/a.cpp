#include <bits/stdc++.h>
using namespace std;

int main() {
  char a, b;
  cin >> a >> b;
  int ans = (a == 'H') + (b == 'H');
  if (ans%2)
    cout << "D\n";
  else
    cout << "H\n";
  return 0;
}
