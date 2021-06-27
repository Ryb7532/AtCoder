#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  int N;
  cin >> N;
  vector<pii> P(N);
  set<ll> s;
  s.insert(0);
  s.insert(N+1);
  rep(i,N) {
    cin >> P[i].first;
    P[i].second = i+1;
  }
  sort(all(P));
  s.insert(P.back().second);
  P.pop_back();
  ll ans = 0;
  while (!P.empty()) {
    ll fir = P.back().first,sec = P.back().second;
    auto itl = s.lower_bound(sec);
    auto itr = itl;
    itl--;
    if (itl != s.begin()) {
      ans += fir*(*itl-*(--itl))*(*itr-sec);
      itl++;
    }
    if (++itr != s.end()) {
      ll tmp = *itr;
      ans += fir*(sec-*itl)*(tmp-*(--itr));
    }
    s.insert(sec);
    P.pop_back();
  }
  print(ans);
  return 0;
}
