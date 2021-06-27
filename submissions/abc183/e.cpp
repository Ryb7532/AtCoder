#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"

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
  int H,W;
  cin >> H >> W;
  vec<string> S(H);
  vec<vec<vec<mint>>> dp(H, vec<vec<mint>>(W, vec<mint>(4)));
  dp[H-1][W-1][0]=1;
  rep(i,H) {
    cin >> S[i];
  }
  for (int i=H-1; i>=0; i--) {
    for (int j=W-1; j>=0; j--) {
      if (S[i][j] == '#')
        continue;
      if (i!=H-1 && S[i+1][j]!='#')
        dp[i][j][0] += dp[i+1][j][1];
      if (j!=W-1 && S[i][j+1]!='#')
        dp[i][j][0] += dp[i][j+1][2];
      if (i!=H-1 && j!=W-1 && S[i+1][j+1]!='#')
        dp[i][j][0] += dp[i+1][j+1][3];
      for (int k=1; k<4; k++)
        dp[i][j][k] = dp[i][j][0];
      if (i!=H-1 && S[i+1][j]!='#')
        dp[i][j][1] += dp[i+1][j][1];
      if (j!=W-1 && S[i][j+1]!='#')
        dp[i][j][2] += dp[i][j+1][2];
      if (i!=H-1 && j!=W-1 && S[i+1][j+1]!='#')
        dp[i][j][3] += dp[i+1][j+1][3];
    }
  }
  print(dp[0][0][0]);
  return 0;
}
