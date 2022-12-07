#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.length();
  for (int i=0; i<n; i+=2)
    cout << s[i];
  cout << '\n';
  return 0;
}
