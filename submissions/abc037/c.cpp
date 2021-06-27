#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;
  int a[N];
  for (int i=0; i<N; i++)
    cin >> a[i];
  ll ans = 0, sum = 0;
  for (int i=0; i<K-1; i++)
    sum += a[i];
  for (int i=0; i<N-K+1; i++) {
    sum += a[i+K-1];
    ans += sum;
    sum -= a[i];
  }
  cout << ans << endl;
  return 0;
}
