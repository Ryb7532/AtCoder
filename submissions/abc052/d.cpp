#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  ll X[N];
  ll ans = 0;
  for (int i=0; i<N; i++)
    cin >> X[i];
  for (int i=1; i<N; i++) {
    if ((X[i]-X[i-1])*A < B)
      ans += (X[i]-X[i-1])*A;
    else
      ans += B;
  }
  cout << ans << endl;
  return 0;
}