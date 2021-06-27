#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << a << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
const ll MOD = 1e9+7;


int main() {
  ll N,A,B;
  cin >> N >> A >> B;
  multiset<pair<ll,ll>> num;
  rep(i,N) {
    ll a;
    cin >> a;
    num.insert({0,a});
  }
  if (A == 1) {
    for (auto &e : num)
      print(e.second);
    return 0;
  }
  while (B>0) {
    auto m = num.begin();
    auto M = num.end();
    M--;
    pair<ll,ll> n;
    n = {A*(m->first),A*(m->second)};
    n.first += n.second/MOD;
    n.second %= MOD;
    if (n.first > M->first || (n.first == M->first && n.second > M->second))
      break;
    num.erase(m);
    num.insert(n);
    B--;
  }
  ll C = B/N, p = 1;
  B %= N;
  while (C>0) {
    p *= A;
    p %= MOD;
    C--;
  }
  while (B>0) {
    auto m = num.begin();
    auto M = num.end()--;
    pair<ll,ll> n;
    n = {A*(m->first),A*(m->second)};
    n.first += n.second/MOD;
    n.second %= MOD;
    num.erase(m);
    num.insert(n);
    B--;
  }
  for (auto &e : num) {
    print((e.second*p)%MOD);
  }
  return 0;
}
