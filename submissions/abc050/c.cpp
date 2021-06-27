#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

int main() {
  int N, a;
  vector<int> A;
  ll ans = 1;
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> a;
    A.push_back(a);
  }
  sort(A.begin(), A.end());
  if (N%2) {
    for (int i=0; i<N; i++) {
      if (A[i] != (i+1)/2 * 2) {
        cout << 0 << endl;
        return 0;
      }
    }
  } else {
    for (int i=0; i<N; i++) {
      if (A[i] != i/2 * 2 + 1) {
        cout << 0 << endl;
        return 0;
      }
    }
  }
  for (int i=0; i<N/2; i++) {
    ans *= 2;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}