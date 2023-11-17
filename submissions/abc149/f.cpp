#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

// Mod int
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

template<typename data_t, typename sum_t>
class ReRooting {
private:
  struct Edge { int to; data_t data; sum_t dp, ndp; };
  // Function to merge data
  using F = function<sum_t(sum_t,sum_t)>;
  // Function to calculate the value of the subtree
  using G = function<sum_t(sum_t,data_t)>;

  vector<vector<Edge>> g;
  vector<sum_t> subdp, dp;
  const F f1;
  const G f2;
  const sum_t ident;

  void dfs_sub(int n, int p) {
    for (auto &e: g[n]) {
      if (e.to == p)
        continue;
      dfs_sub(e.to, n);
      subdp[n] = f1(subdp[n], f2(subdp[e.to], e.data));
    }
  }

  void dfs_all(int n, int p, const sum_t &top) {
    sum_t buff{ident};
    rep(i,g[n].size()) {
      auto &e = g[n][i];
      e.ndp = buff;
      e.dp = f2(p == e.to ? top : subdp[e.to], e.data);
      buff = f1(buff, e.dp);
    }
    dp[n] = buff;
    buff = ident;
    rrep(i,g[n].size()) {
      auto &e = g[n][i];
      if(e.to != p)
        dfs_all(e.to, n, f1(e.ndp, buff));
      e.ndp = f1(e.ndp, buff);
      buff = f1(buff, e.dp);
    }
  }

public:
  ReRooting(int n, const F &f1, const G &f2, const sum_t &ident) :
    g(n), f1(f1), f2(f2), ident(ident), subdp(n, ident), dp(n, ident) {}

  void add_edge(int u, int v, const data_t &d) {
    g[u].emplace_back((Edge){v, d, ident, ident});
    g[v].emplace_back((Edge){u, d, ident, ident});
  }

  void add_edge_bi(int u, int v, const data_t &d, const data_t &e) {
    g[u].emplace_back((Edge){v, d, ident, ident});
    g[v].emplace_back((Edge){u, e, ident, ident});
  }

  vector<sum_t> solve() {
    dfs_sub(0,-1);
    dfs_all(0,-1,ident);
    return dp;
  }
};

int main() {
  int N;
  cin >> N;
  using data_t = int;
  using sum_t = pair<mint,int>;
  auto f = [](sum_t a, sum_t b) {
    return sum_t{a.first + b.first - 1, a.second + b.second};
  };
  auto g = [](sum_t a, data_t b) {
    return sum_t{mint(2).pow(a.second + b), a.second + b};
  };
  ReRooting<data_t,sum_t> tree(N, f, g, sum_t{0,0});
  rep(_,N-1) {
    int a,b;
    cin >> a >> b;
    tree.add_edge_bi(--a, --b, 1, 1);
  }
  auto dp = tree.solve();
  mint res = 0;
  rep(i,N) {
    res += mint(2).pow(N-1) - 1 - dp[i].first;
  }
  res /= mint(2).pow(N);
  print(res);
  return 0;
}