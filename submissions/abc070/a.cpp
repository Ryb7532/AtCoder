#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n/100 == n%10)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
