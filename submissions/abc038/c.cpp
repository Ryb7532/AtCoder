#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  int a[N+1], b = 0, u = 0;
  a[N] = 0;
  ll ans = 0;
  for (int i=0; i<N; i++)
    cin >> a[i];
  while (b<N) {
    while (a[u] < a[u+1])
      u++;
    ans += u-b+1;
    if (u == b)
      u++;
    b++;
  }
  cout << ans << endl;
  return 0;
}
