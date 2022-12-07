#include <bits/stdc++.h>
using namespace std;

int main() {
  string S_1, S_2;
  cin >> S_1 >> S_2;
  int res = S_1.compare(S_2), len1 = S_1.size(), len2 = S_2.size();
  if (len1 == len2) {
    if (res == 0)
      cout << "EQUAL\n";
    else if (res > 0)
      cout << "GREATER\n";
    else
      cout << "LESS\n";
  } else if (len1 > len2)
    cout << "GREATER\n";
  else
    cout << "LESS\n";
  return 0;
}
