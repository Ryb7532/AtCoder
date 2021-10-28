#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  ll L;
  int Q;
  cin >> L >> Q;
  set<ll> cut;
  cut.insert(0);
  cut.insert(L);
  rep(_,Q) {
    int c;
    ll x;
    cin >> c >> x;
    if (c == 1) {
      cut.insert(x);
    } else {
      auto it = cut.lower_bound(x);
      ll res = *it;
      res -= *(--it);
      print(res);
    }
  }
  return 0;
}
