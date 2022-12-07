#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int X, N;
  cin >> X >> N;
  int a[102], P, ans = 0;
  fill(a, a+102, 0);
  for (int i=0; i<N; i++) {
    cin >> P;
    a[P]++;
  }
  for (int i=0; i<=101; i++) {
    if (a[i])
      continue;
    if (abs(X-i) < abs(X-ans))
      ans = i;
  }
  cout << ans << endl;
  return 0;
}
