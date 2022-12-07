#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A;
  string S;
  cin >> A >> S;
  int B = 0;
  for (int i=0; i<4; i++) {
    if (i == 1) continue;
    B *= 10;
    B += S[i]-'0';
  }
  long long ans = A*B;
  cout << ans/100 << endl;
  return 0;
}
