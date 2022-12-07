#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int T;
  cin >> T;
  rep(_,T) {
    vector<ll> C(3);
    rep(i,3) {
      cin >> C[i];
    }
    ll res = 1e18;
    rep(i,3) {
      rep(j,3) {
        if (i==j)
          continue;
        if (C[i]<C[j])
          continue;
        if ((C[i]-C[j])%3 != 0)
          continue;
        res = min(res, C[i]);
      }
    }
    if (res == 1e18)
      res = -1;
    print(res);
  }
  return 0;
}
