#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, Q;
  cin >> N >> Q;
  int L, R, T, ans[N];
  fill(ans, ans+N, 0);
  for (int i=0; i<Q; i++) {
    cin >> L >> R >> T;
    L--;
    fill(ans+L, ans+R, T);
  }
  for (int i=0; i<N; i++)
    cout << ans[i] << endl;
  return 0;
}
