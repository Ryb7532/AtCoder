#include <iostream>
using namespace std;

int main() {
  int x, a, b;
  cin >> x >> a >> b;
  if (abs(x-a) < abs(x-b))
    cout << "A\n";
  else
    cout << "B\n";
  return 0;
}
