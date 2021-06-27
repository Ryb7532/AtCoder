#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;

int main() {
  string S;
  string s[2] = {"dream", "erase"};
  cin >> S;
  int n = S.size(), p = -1;
  for (int i=0; i<n; i++) {
    if (S[i] == 'd')
      if (S.compare(i, 5, s[0]) == 0) {
        p = 0;
        i += 4;
      } else {
        cout << "NO" << endl;
        return 0;
      }
    else if (S[i] == 'e') {
      if (S.compare(i, 5, s[1]) == 0) {
        p = 1;
        i += 4;
      } else if (p == 0 && S[i+1] == 'r') {
        p = -1;
        i++;
      }
    } else if (p == 1 && S[i] == 'r')
      p = -1;
    else {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}