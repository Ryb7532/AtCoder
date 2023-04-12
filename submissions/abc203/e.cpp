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
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  ll N,M;
  cin >> N >> M;
  vector<pair<int,int>> P(M);
  rep(i,M) {
    cin >> P[i].first >> P[i].second;
  }
  sort(all(P));
  P.push_back({0,0});
  ll px = 0;
  set<ll> res;
  res.insert(N);
  vector<ll> ad, rm;
  rep(i,M+1) {
    if (px != P[i].first) {
      for (auto e: ad) {
        res.insert(e);
      }
      for (auto e: rm) {
        res.erase(e);
      }
      ad.clear();
      rm.clear();
      px = P[i].first;
    }
    ll y = P[i].second;
    if (res.find(y)!=res.end() && res.find(y-1)==res.end() && res.find(y+1)==res.end()) {
      rm.push_back(y);
    } else if (res.find(y)==res.end() && (res.find(y-1)!=res.end() || res.find(y+1)!=res.end())) {
      ad.push_back(y);
    }
  }
  print(res.size());
  return 0;
}
