#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int fa = -1, lz = 0;
  for (int i=0; i<s.size(); i++) {
    if (s[i] == 'A' && fa == -1)
      fa = i;
    if (s[i] == 'Z')
      lz = i;
  }
  cout << lz-fa+1 << endl;
  return 0;
}
