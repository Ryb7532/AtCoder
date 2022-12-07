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


vector<ll> divisor(ll n) {
  vector<ll> res;
  for (ll i=1; i*i<=n; i++) {
    if (n%i != 0) {
      continue;
    }
    res.push_back(i);
    if (i*i != n)
      res.push_back(n/i);
  }
  sort(all(res));
  return res;
}


ll gcd(ll a, ll b) {
  while (b!=0) {
    a %= b;
    swap(a,b);
  }
  return a;
}

ll lcm(ll a, ll b) {
  ll g = gcd(a,b);
  return a/g*b;
}

int main() {
  int N;
  cin >> N;
  vector<pair<ll,ll>> C(N);
  rep(i,N) {
    cin >> C[i].first >> C[i].second;
  }
  ll res = 0;
  vector<ll> div0 = divisor(C[0].first), div1 = divisor(C[0].second);
  for (ll X: div0) {
    for (ll Y: div1) {
      bool can = true;
      rep(i,N) {
        if ((C[i].first%X!=0||C[i].second%Y!=0) && (C[i].first%Y!=0||C[i].second%X!=0)) {
          can = false;
          break;
        }
      }
      if (can) {
        res = max(res, lcm(X,Y));
      }
    }
  }
  print(res);
  return 0;
}
