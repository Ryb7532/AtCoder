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
  int N;
  cin >> N;
  vector<pair<ll,ll>> C((1<<N)-1);
  rep(i,(1<<N)-1) {
    int c;
    cin >> c;
    C[i] = {c, i+1};
  }
  sort(all(C));
  vector<bool> can(1<<N, false);
  set<ll> used;
  ll res = 0;
  rep(i,(1<<N)-1) {
    ll n = C[i].second;
    if (can[n])
      continue;
    res += C[i].first;
    set<ll> new_used;
    new_used.insert(n);
    for (ll e: used) {
      new_used.insert(e);
      new_used.insert(e^n);
      can[e^n] = true;
    }
    used = new_used;
  }
  print(res);
  return 0;
}
