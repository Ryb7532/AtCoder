#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int n = S.length();
  bool c;
  for (int i=n-2; i>0; i-=2) {
    c = true;
    int h = i/2;
    for (int j=0; j<h; j++)
      if (S[j] != S[j+h])
        c = false;
    if (c) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
