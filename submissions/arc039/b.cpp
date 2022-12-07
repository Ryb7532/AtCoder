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

const ll mod = 1e9+7;
struct mint {
  ll x;
  mint(ll x=0) : x((x%mod+mod)%mod) {}
  mint &operator+=(const mint &p) { if((x += p.x) >= mod) x -= mod; return *this; }
  mint &operator-=(const mint &p) { if((x += mod - p.x) >= mod) x -= mod; return *this; }
  mint &operator*=(const mint &p) { x = x * p.x % mod; return *this; }
  mint &operator/=(const mint &p) { *this *= p.inverse(); return *this; }
  mint operator-() const { return mint(-x); }
  mint operator+(const mint &p) const { return mint(*this) += p; }
  mint operator-(const mint &p) const { return mint(*this) -= p; }
  mint operator*(const mint &p) const { return mint(*this) *= p; }
  mint operator/(const mint &p) const { return mint(*this) /= p; }
  bool operator==(const mint &p) const { return x == p.x; }
  bool operator!=(const mint &p) const { return x != p.x; }
  mint inverse() const {
    ll a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return mint(u);
  }
  mint pow(ll n) const {
    mint ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os, const mint &p) { return os << p.x; }
  friend istream &operator>>(istream &is, mint &a) {
    ll t;
    is >> t;
    a = mint(t);
    return (is);
  }
};

template< typename T >
struct Combination {
  vector< T > _fact, _rfact, _inv;
  Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1) {
    _fact[0] = _rfact[sz] = _inv[0] = 1;
    for(int i=1; i<=sz; i++) _fact[i] = _fact[i-1]*i;
    _rfact[sz] /= _fact[sz];
    for(int i=sz-1; i>=0; i--) _rfact[i] = _rfact[i+1]*(i+1);
    for(int i=1; i<=sz; i++) _inv[i] = _rfact[i]*_fact[i-1];
  }
  inline T fact(int k) const { return _fact[k]; }
  inline T rfact(int k) const { return _rfact[k]; }
  inline T inv(int k) const { return _inv[k]; }
  T P(int n, int r) const {
    if(r < 0 || n < r) return 0;
    return fact(n) * rfact(n-r);
  }
  T C(int p, int q) const {
    if(q < 0 || p < q) return 0;
    return fact(p) * rfact(q) * rfact(p-q);
  }
  T H(int n, int r) const {
    if(n < 0 || r < 0) return (0);
    return r == 0 ? 1 : C(n+r-1, r);
  }
};
Combination<mint> c(1000);


int main() {
  int N,K;
  cin >> N >> K;
  mint ans;
  if (K<N) {
    ans = c.C(N+K-1,K);
  } else {
    K %= N;
    ans = c.C(N,K);
  }
  print(ans);
  return 0;
}
