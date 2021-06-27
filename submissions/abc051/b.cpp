#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int K, S;
  cin >> K >> S;
  int ans = 0;
  for (int i=0; i<=K; i++) {
    for (int j=0; j<=K; j++) {
      if (S-i-j <= K && S-i-j >= 0)
        ans ++;
    }
  }
  cout << ans << endl;
  return 0;
}
