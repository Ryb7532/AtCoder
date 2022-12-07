#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


const ll N = 1<<20;


int main() {
  int Q;
  cin >> Q;
  set<int> noupd;
  vec<ll> val(N, -1);
  rep(i,N) {
    noupd.insert(i);
  }
  rep(_,Q) {
    int t;
    ll x;
    cin >> t >> x;
    if (t == 2) {
      print(val[x%N]);
    } else {
      auto it = noupd.lower_bound(x%N);
      if (it == noupd.end())
        it = noupd.lower_bound(0);
      int h = *it;
      noupd.erase(it);
      val[h] = x;
    }
  }
  return 0;
}
