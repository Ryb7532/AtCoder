#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S, T;
  cin >> S >> T;
  int n = S.size(), ans = 0;
  for (int i=0; i<n; i++)
    if (S[i] != T[i])
      ans++;
  cout << ans << endl;
  return 0;
}
