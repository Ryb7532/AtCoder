#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int n = s.size(), c = 0, m = 1e5;
  for (int i=0; i<n; i++) {
    if (s[i] == 'g')
      c++;
    else
      c--;
  }
  cout << c/2 << endl;
  return 0;
}