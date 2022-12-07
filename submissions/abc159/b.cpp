#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.length();
  bool check = true;
  for (int i=0; i<(n-1)/2; i++) {
    if (s[i] == s[(n-1)/2-i-1])
      continue;
    check = false;
    break;
  }
  for (int i=(n+1)/2; i<n; i++) {
    if (s[i] == s[n-i-1])
      continue;
    check = false;
    break;
  }
  if (check)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
