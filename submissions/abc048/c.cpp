#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, x;
  cin >> N >> x;
  int a[N];
  ll ans = 0;
  for (int i=0; i<N; i++)
    cin >> a[i];
  if (a[0] > x) {
    ans += a[0]-x;
    a[0] = x;
  }
  for (int i=1; i<N; i++) {
    if (a[i-1]+a[i] > x) {
      ans += a[i-1]+a[i]-x;
      a[i] -= a[i-1]+a[i]-x;
    }
  }
  cout << ans << endl;
  return 0;
}