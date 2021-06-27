#include <bits/stdc++.h>
using namespace std;

int main() {
  long H, W;
  cin >> H >> W;
  if (H%3 == 0 || W%3 == 0) {
    cout << 0 << endl;
    return 0;
  }
  long ans = min(H, W);
  for (int i=1; i<H; i++) {
    long Smax = max(i*((W+1)/2), (H-i)*W), Smin = min(i*(W/2), (H-i)*W);
    ans = min(ans, Smax-Smin);
  }
  for (int i=1; i<W; i++) {
    long Smax = max(i*((H+1)/2), (W-i)*H), Smin = min(i*(H/2), (W-i)*H);
    ans = min(ans, Smax-Smin);
  }
  cout << ans << endl;
  return 0;
}