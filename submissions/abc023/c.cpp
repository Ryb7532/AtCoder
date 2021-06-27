#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end()

int main() {
  int R, C, K, N;
  cin >> R >> C >> K >> N;
  int r[N], c[N];
  vector<ll> cntr(R, 0), cntc(C, 0), c_num(C+1, 0);
  ll ans = 0;
  rep(i, N) {
    cin >> r[i] >> c[i];
    r[i]--; c[i]--;
    cntr[r[i]]++;
    cntc[c[i]]++;
  }
  rep(i, C) {
    c_num[cntc[i]]++;
  }
  rep(i, R) {
    if (K-cntr[i]>C || K-cntr[i]<0)
      continue;
    ans += c_num[K-cntr[i]];
  }
  rep(i, N) {
    if (cntr[r[i]]+cntc[c[i]] == K)
      ans--;
    if (cntr[r[i]]+cntc[c[i]] == K+1)
      ans++;
  }
  print(ans);
  return 0;
}
