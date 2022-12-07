#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
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
  int H,W;
  int K;
  cin >> H >> W >> K;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  x1--;
  y1--;
  x2--;
  y2--;
  vector<mint> pattern(4);
  pattern[0] += 1;
  rep(_,K) {
    mint p0, p1, p2, p3;
    p0 = pattern[1]*(W-1) + pattern[2]*(H-1);
    p1 = pattern[0] + pattern[1]*(W-2) + pattern[3]*(H-1);
    p2 = pattern[0] + pattern[2]*(H-2) + pattern[3]*(W-1);
    p3 = pattern[1] + pattern[2] + pattern[3]*(H+W-4);
    pattern[0] = p0;
    pattern[1] = p1;
    pattern[2] = p2;
    pattern[3] = p3;
  }
  if (x1 == x2 && y1 == y2) {
    print(pattern[0]);
  } else if (x1 == x2) {
    print(pattern[1]);
  } else if (y1 == y2) {
    print(pattern[2]);
  } else {
    print(pattern[3]);
  }
  return 0;
}
