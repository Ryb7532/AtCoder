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


// Combination
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
Combination<mint> c(1000005);


int main() {
  int N,M;
  cin >> N >> M;
  vector<vector<bool>> F(2*N+1, vector<bool>(2*N+1, false));
  rep(_,M) {
    int a,b;
    cin >> a >> b;
    F[a][b-a] = true;
  }
  vector<vector<mint>> dp(2*N+5, vector<mint>(N+1));
  rrep(i,2*N+5) {
    dp[i][0] = 1;
  }
  rrep(i,2*N) {
    for (int j=1; i+2*j<=2*N; j++) {
      rep(k,j) {
        if (!F[i+1][2*k+1])
          continue;
        dp[i][j] += dp[i+1][k] * dp[i+2*k+2][j-k-1] * c.C(j, k+1);
      }
    }
  }
  print(dp[0][N]);
  return 0;
}
