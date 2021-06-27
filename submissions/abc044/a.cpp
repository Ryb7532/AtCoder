#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, K, X, Y, ans = 0;
  cin >> N >> K >> X >> Y;
  if (N>K) {
    ans += (N-K)*Y;
    N = K;
  }
  ans += N*X;
  cout << ans << endl;
  return 0;
}
