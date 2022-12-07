#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()

const ll mod = 1e4+7;
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


int main() {
  int n;
  cin >> n;
  mint t[n+2];
  t[0] = t[1] = 0; t[2] = 1;
  reps(i, 3, n) {
    t[i] = t[i-1]+t[i-2]+t[i-3];
  }
  print(t[n-1]);
  return 0;
}
