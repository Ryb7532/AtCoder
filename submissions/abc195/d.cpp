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
  int N,M,Q;
  cin >> N >> M >> Q;
  vec<pair<ll,ll>> Bag(N);
  rep(i,N)
    cin >> Bag[i].first >> Bag[i].second;
  sort(all(Bag));
  vec<pair<ll,int>> Box(M);
  rep(i,M) {
    cin >> Box[i].first;
    Box[i].second = i;
  }
  sort(all(Box));
  rep(_,Q) {
    int L,R;
    cin >> L >> R;
    L--; R--;
    multiset<ll, greater<ll>> s;
    ll res = 0;
    int id = 0;
    rep(i,M) {
      if (Box[i].second>=L && Box[i].second<=R)
        continue;
      while (id<N && Bag[id].first<=Box[i].first) {
        s.insert(Bag[id].second);
        id++;
      }
      if (s.empty())
        continue;
      res += *(s.begin());
      s.erase(s.begin());
    }
    print(res);
  }
  return 0;
}
