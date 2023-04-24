#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(int)n; i++)
#define rrep(i,n) for (int i=(int)n-1; i>=0; i--)
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


int main() {
  int N,M;
  cin >> N >> M;
  vector<vector<vector<vector<mint>>>> dp(N+1, vector<vector<vector<mint>>>(M+1, vector<vector<mint>>(M+1, vector<mint>(M+1))));
  dp[0][M][M][M] = 1;
  rep(i,N) {
    rep(j,M+1) {
      rep(k,M+1) {
        if (k<j)
          continue;
        if (j!=M && k==j)
          continue;
        rep(l,M+1) {
          if (l<k)
            continue;
          if (k!=M && l==k)
            continue;
          rep(x,M) {
            if (j>=x) {
              dp[i+1][x][k][l] += dp[i][j][k][l];
            } else if (k>=x) {
              dp[i+1][j][x][l] += dp[i][j][k][l];
            } else if (l>=x) {
              dp[i+1][j][k][x] += dp[i][j][k][l];
            }
          }
        }
      }
    }
  }
  mint res;
  rep(j,M) {
    rep(k,M) {
      if (k<=j)
        continue;
      rep(l,M) {
        if (l<=k)
          continue;
        res += dp[N][j][k][l];
      }
    }
  }
  print(res);
  return 0;
}
