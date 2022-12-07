#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  int len = S.size();
  bool check = true;
  for (int i=0; i<len; i++)
    if (S[i] != T[i])
      check = false;
  if (check)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
