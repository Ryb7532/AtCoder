#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, T;
  cin >> N >> T;
  int A, B[N], m, M = 0;
  cin >> m;
  for (int i=1; i<N; i++) {
    cin >> A;
    B[i] = A - m;
    m = min(m, A);
    M = max(M, B[i]);
  }
  int ans = 0;
  for (int i=1; i<N; i++)
    if (B[i] == M)
      ans++;
  cout << ans << endl;
  return 0;
}