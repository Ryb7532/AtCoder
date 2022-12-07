#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())
typedef tuple<ll,ll,ll> road;


int main() {
  int N, Q;
  ll s, t, x, d;
  cin >> N >> Q;
  vector<road> r;
  rep(i,N) {
    cin >> s >> t >> x;
    r.push_back(make_tuple(s-x, t-x, x));
  }
  rsort(r);
  set<pair<ll,ll>> u; multiset<ll> p;
  rep(i,Q) {
    cin >> d;
    while (!r.empty()) {
      if (get<0>(r.back())<=d) {
        auto e = r.back();
        r.pop_back();
        u.insert(make_pair(get<1>(e), get<2>(e)));
        p.insert(get<2>(e));
      }
      else
        break;
    }
    while (!u.empty()) {
      if (u.begin()->first<=d) {
        auto it = p.find(u.begin()->second);
        p.erase(it);
        u.erase(u.begin());
      } else
        break;
    }
    if (p.empty()) {
      print(-1);
    } else {
      print(*(p.begin()));
    }
  }
  return 0;
}
