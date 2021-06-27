#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, M;
  cin >> N >> M;
  long ans;
  ans = min(N, M/2);
  if (M-N*2>0) {
    ans += (M-N*2)/4;
  }
  cout << ans << endl;
  return 0;
}