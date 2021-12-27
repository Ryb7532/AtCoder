#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
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


const ll mod = 998244353;
struct mint {
  ll x;
  mint(ll x=0) : x((x%mod+mod)%mod) {}
  mint &operator+=(const mint &p) { if((x += p.x) >= mod) x -= mod; return *this; }
  mint &operator-=(const mint &p) { if((x += mod - p.x) >= mod) x -= mod; return *this; }
  mint &operator*=(const mint &p) { x = x * p.x % mod; return *this; }
  mint &operator/=(const mint &p) { *this *= p.inverse(); return *this; }
  mint operator-() const { return mint(-x); }
  mint operator+(const mint &p) const { return mint(*this) += p; }
  friend mint operator+(const int &c,const mint &p) { return mint(c) += p; }
  mint operator-(const mint &p) const { return mint(*this) -= p; }
  friend mint operator-(const int &c,const mint &p) { return mint(c) -= p; }
  mint operator*(const mint &p) const { return mint(*this) *= p; }
  friend mint operator*(const int &c,const mint &p) { return mint(c) *= p; }
  mint operator/(const mint &p) const { return mint(*this) /= p; }
  friend mint operator/(const int &c,const mint &p) { return mint(c) /= p; }
  bool operator==(const mint &p) const { return x == p.x; }
  friend bool operator==(const int &c,const mint &p) { return mint(c) == p; }
  bool operator!=(const mint &p) const { return x != p.x; }
  friend bool operator!=(const int &c, const mint &p) { return mint(c) != p; }
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
  friend ostream &operator<<(ostream &os,const mint &p) { return os << p.x; }
  friend istream &operator>>(istream &is,mint &a) {
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
  T C(int p, int q) const { // pCq
    if(q < 0 || p < q) return 0;
    return fact(p) * rfact(q) * rfact(p-q);
  }
  T H(int n, int r) const {
    if(n < 0 || r < 0) return (0);
    return r == 0 ? 1 : C(n+r-1, r);
  }
};
Combination<mint> c(2e5+20);


template <typename T>
struct PrimeFact {
  vector<T> spf;
  PrimeFact(T N) { init(N); }
  void init(T N) { // preprocess
    spf.assign(N + 1, 0);
    for (T i = 0; i <= N; i++)
      spf[i] = i;
    for (T i = 2; i * i <= N; i++)
      if (spf[i] == i)
        for (T j = i * i; j <= N; j += i)
          if (spf[j] == j)
            spf[j] = i;
  }
  map<T, T> get(T n) { // calc prime factorization
    map<T, T> m;
    while (n != 1) {
      m[spf[n]]++;
      n /= spf[n];
    }
    return m;
  }
  T cntDivisor(T n) { // calc number of divisor
    T p = 0, cnt = 0, res = 1;
    while (n != 1) {
      if (p == spf[n])
        cnt++;
      else {
        res *= cnt+1;
        p = spf[n];
        cnt = 1;
      }
      n /= spf[n];
    }
    res *= cnt+1;
    return res;
  }
};


int main() {
  int N,M;
  cin >> N >> M;
  PrimeFact<int> p(2e5+1);
  mint res = 0;
  rep(i,M) {
    mint tmp = 1;
    auto pf = p.get(i+1);
    for (auto e: pf) {
      tmp *= c.C(N-1+e.second, N-1);
    }
    res += tmp;
  }
  print(res);
  return 0;
}
