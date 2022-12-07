#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  string s = "WBWBWWBWBWBW";
  int i;
  for (i=0; i<12; i++) {
    if (S.substr(0, 12-i).compare(s.substr(i, 12-i)) == 0)
      break;
  }
  if (i <= 1)
    cout << "Do" << endl;
  else if (i <= 3)
    cout << "Re" << endl;
  else if (i <= 4)
    cout << "Mi" << endl;
  else if (i <= 6)
    cout << "Fa" << endl;
  else if (i <= 8)
    cout << "So" << endl;
  else if (i <= 10)
    cout << "La" << endl;
  else
    cout << "Si" << endl;
  return 0;
}
