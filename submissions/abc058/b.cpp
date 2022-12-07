#include <bits/stdc++.h>
using namespace std;

int main() {
  string O, E;
  cin >> O >> E;
  int os = O.size(), es = E.size();
  for (int i=0; i<os; i++) {
    cout << O[i];
    if (i<es)
      cout << E[i];
  }
  cout << endl;
  return 0;
}
