#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int W, H, N;
  cin >> W >> H >> N;
  int x, y, a, b[4] = {0, W, 0, H};
  for (int i=0; i<N; i++) {
    cin >> x >> y >> a;
    a--;
    if (a == 0)
      b[a] = max(b[a], x);
    else if (a == 1)
      b[a] = min(b[a], x);
    else if (a == 2)
      b[a] = max(b[a], y);
    else
      b[a] = min(b[a], y);
  }
  int ans = max(0, b[1]-b[0]) * max(0, b[3]-b[2]);
  cout << ans << endl;
  return 0;
}
