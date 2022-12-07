#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


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


int main() {
  int N, K; ll a;
  cin >> N >> K;
  vector<ll> m, p;
  rep(i, N) {
    cin >> a;
    if (a>=0)
      p.push_back(a);
    else
      m.push_back(-a);
  }
  sort(all(p)); reverse(all(p));
  sort(all(m)); reverse(all(m));
  int idp = 0, idm = 0, ps = p.size(), ms = m.size();
  mint ans = 1;
  if (K%2 && ps == 0) {
    rep1(i, K) {
      ans *= -m[ms-i];
    }
    print(ans);
    return 0;
  }
  if (K%2) {
    ans *= p[0];
    idp++;
  }
  while (idp+idm<K) {
    if (idp<ps-1) {
      ll vp = p[idp]*p[idp+1];
      if (idm<ms-1) {
        ll vm = m[idm]*m[idm+1];
        if (vp > vm) {
          ans *= vp%mod;
          idp += 2;
        } else {
          ans *= vm%mod;
          idm += 2;
        }
      } else {
        ans *= vp%mod;
        idp += 2;
      }
    } else {
      if (idm<ms-1) {
        ll vm = m[idm]*m[idm+1];
        ans *= vm%mod;
        idm += 2;
      } else {
        ans *= p[idp];
        ans *= -m[idm];
        idp++; idm++;
      }
    }
  }
  print(ans);
  return 0;
}
