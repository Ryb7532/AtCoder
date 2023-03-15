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


int main() {
  int N,M;
  cin >> N >> M;
  vector<ll> A(3), B(3);
  rep(i,3) {
    cin >> A[i] >> B[i];
  }
  set<pair<ll,ll>> Obj;
  rep(i,M) {
    int X,Y;
    cin >> X >> Y;
    Obj.insert({X,Y});
  }
  vector<vector<vector<mint>>> dp(N+2, vector<vector<mint>>(N+2, vector<mint>(N+2)));
  dp[0][0][0] = 1;
  rep(a,N+1) {
    rep(b,N+1-a) {
      rep(c,N+1-a-b) {
        ll X = A[0]*a + A[1]*b + A[2]*c;
        ll Y = B[0]*a + B[1]*b + B[2]*c;
        if (Obj.find({X,Y}) != Obj.end())
          dp[a][b][c] = 0;
        dp[a+1][b][c] += dp[a][b][c];
        dp[a][b+1][c] += dp[a][b][c];
        dp[a][b][c+1] += dp[a][b][c];
      }
    }
  }
  mint res = 0;
  rep(a,N+1) {
    rep(b,N+1-a) {
      res += dp[a][b][N-a-b];
    }
  }
  print(res);
  return 0;
}
