#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"
#define printYorN(f) cout << (f ? Yes : No) << endl


int main() {
  ll K;
  cin >> K;
  ll N = 1;
  ll K_ = K;
  for (ll i=2; i*i<=K_; i++) {
    int cnt = 0;
    while (K_%i == 0) {
      cnt++;
      K_ /= i;
    }
    if (cnt == 0)
      continue;
    ll l = 0, r = K;
    while (r-l > 1) {
      ll m = (r+l)/2;
      ll m_ = m;
      ll mcnt = 0;
      while (m_ >= i) {
        mcnt += m_/i;
        m_ /= i;
      }
      if (cnt <= mcnt)
        r = m;
      else
        l = m;
    }
    N = max(N,r);
  }
  N = max(N, K_);
  print(N);
  return 0;
}
