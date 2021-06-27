#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int ans = 0, x = 0;
  for (int i=0; i<N; i++) {
    if (S[i] == 'I') {
      x++;
      ans = max(ans, x);
    } else
      x--;
  }
  cout << ans << endl;
  return 0;
}
