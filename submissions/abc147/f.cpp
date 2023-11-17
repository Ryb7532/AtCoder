#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

int main() {
  int N;
  ll X,D;
  const ll INF = 1e18;
  cin >> N >> X >> D;
  if (D == 0) {
    if (X == 0)
      print(1);
    else
      print(N+1);
    return 0;
  }
  if (D < 0) {
    D *= -1;
    X *= -1;
  }
  map<ll, set<pair<ll,ll>>> m;
  ll res = 0;
  rep(i,N+1) {
    ll v = ((X*i) % D + D) % D;
    ll L = X*i/D, R = X*i/D;
    L += 1ll*i*(i-1)/2;
    R += 1ll*i*(2*N-i-1)/2;
    m[v].insert({L, R});
  }
  for (auto [_,s]: m) {
    ll pre = -INF;
    for (auto p: s) {
      if (pre > p.second)
        continue;
      if (pre < p.first) {
        res += p.second - p.first + 1;
      } else {
        res += p.second - pre;
      }
      pre = p.second;
    }
  }
  print(res);
  return 0;
}