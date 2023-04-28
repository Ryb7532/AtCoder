#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,s,e) for (int i=s; i<(int)(e); i++)
#define repn(i,n) rep(i,0,n)
#define rrep(i,s,e) for (int i=s-1; i>=e; i--)
#define rrepn(i,n) rrep(i,n,0)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


ll S(ll a) {
  ll res = 0;
  while (a > 0) {
    res += a%10;
    a /= 10;
  }
  return res;
}

int main() {
  ll K;
  cin >> K;
  vector<ll> res;
  res.push_back(1);
  while (res.size() < K) {
    ll x = res.back() + 1;
    ll nx = x;
    ll base = 1;
    while (x >= base) {
      ll y = (x/base + 1) * base - 1;
      if (y*S(nx) < S(y)*nx)
        nx = y;
      base *= 10;
    }
    res.push_back(nx);
  }
  repn(i,K) {
    print(res[i]);
  }
  return 0;
}
