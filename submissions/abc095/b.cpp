#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, C;
  cin >> N >> C;
  long x[N+1], v[N+1];
  x[0] = 0;
  v[0] = 0;
  for (int i=1; i<=N; i++)
    cin >> x[i] >> v[i];
  long val = 0, rl[N+1], lr[N+1], mrl = 0, mlr = 0, ans = 0;
  rl[0] = 0;
  lr[0] = 0;
  for (int i=1; i<=N; i++) {
    val += v[i];
    if (mrl < val - 2*x[i])
      mrl = val - 2*x[i];
    rl[i] = mrl;
    if (mlr < val - x[i])
      mlr = val - x[i];
    lr[i] = mlr;
  }
  val = 0;
  ans = mlr;
  for (int i=N; i>0; i--) {
    val += v[i];
    ans = max(ans, lr[i-1]+val+2*x[i]-2*C);
    ans = max(ans, rl[i-1]+val+x[i]-C);
  }
  cout << ans << endl;
  return 0;
}
