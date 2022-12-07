#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  int n = S.size(), ans = 0;
  for (int i=1; i<n; i++) {
    if (S[i-1] == S[i])
      continue;
    ans++;
  }
  cout << ans << endl;
  return 0;
}