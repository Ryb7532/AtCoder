#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep1(n) rep2(_,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define printyn(f) cout << ((f) ? "Yes" : "No") << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}
void print() {cout << endl;}
template<typename Arg, typename... Args> void print(const Arg a, const Args... b) {
  cout << a;
  (cout << ... << (cout << ' ', b)) << endl;
}

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
  const int L = 6;
  const int P = 1<<L;
  ll N;
  int M;
  cin >> N >> M;

  vector<string> S(M);
  rep(i,M) {
    cin >> S[i];
  }

  auto check = [&](int a, int l) {
    string t;
    rep(l) {
      t += 'a'+(a&1);
      a >>= 1;
    }
    reverse(all(t));
    fore(s, S) {
      if (t.find(s) != t.npos)
        return false;
    }
    return true;
  };

  if (N < L) {
    int res = 0;
    rep(i, 1<<N) {
      if (check(i,N))
        res++;
    }
    print(res);
    return 0;
  }

  auto matmul = [&](auto &&lhs, auto &&rhs) {
    int n = lhs.size(), m = lhs[0].size(), l = rhs[0].size();
    assert((int)rhs.size() == m);
    vector<vector<mint>> res(n, vector<mint>(l));
    rep(i,n) {
      rep(j,l) {
        rep(k,m) {
          res[i][j] += lhs[i][k] * rhs[k][j];
        }
      }
    }
    return res;
  };

  vector<vector<mint>> coeff(P, vector<mint>(P));
  rep(i,P) {
    if (check(i*2+0, L))
      coeff[i][(i*2+0)&(P-1)] = 1;
    if (check(i*2+1, L))
      coeff[i][(i*2+1)&(P-1)] = 1;
  }

  vector<vector<mint>> res(1, vector<mint>(P));
  vector<vector<mint>> sum(P, vector<mint>(1,1));
  rep(i,P) {
    if (check(i, L))
      res[0][i] = 1;
  }
  N -= L;
  while (N) {
    if (N&1)
      res = matmul(res, coeff);
    coeff = matmul(coeff, coeff);
    N >>= 1;
  }
  print(matmul(res, sum)[0][0]);
  return 0;
}