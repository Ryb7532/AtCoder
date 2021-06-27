#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int n = S.size(), ans = n;
  for (int i=0; i<n-1; i++) {
    if (S[i] != S[i+1]) {
      ans = min(ans, max(i+1, n-i-1));
    }
  }
  cout << ans << endl;
  return 0;
}
