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
#define fore(e,v) for (auto &e: v)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

// Mod int
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

// Union Find Tree
struct UnionFind {
  vector<int> par;
  UnionFind(int n) : par(n, -1) {}

  int root(int a) {
    if (par[a] < 0)
      return a;
    return par[a] = root(par[a]);
  }
  int size(int a) { return -par[root(a)]; }
  void unite(int a, int b) {
    int ra = root(a), rb = root(b);
    if (ra == rb)
      return;
    if (par[ra]>par[rb])
      swap(ra, rb);
    par[ra] += par[rb];
    par[rb] = ra;
    return;
  }
  bool same(int a, int b) {
    int ra = root(a), rb = root(b);
    return ra == rb;
  }
  int &operator[](const int i) { return par[i]; }
};

int H,W;
struct Grid {
  int x;
  int y;

  Grid(int x=0, int y=0) : x(x), y(y) {}

  bool isRange() { return 0<=x && x<H && 0<=y && y<W; }

  vector<Grid> newPos(int step=1, bool dia=false) {
    vector<Grid> res;
    res.emplace_back(Grid(x+step, y));
    res.emplace_back(Grid(x, y+step));
    res.emplace_back(Grid(x-step, y));
    res.emplace_back(Grid(x, y-step));
    if (dia) {
      res.emplace_back(Grid(x+step, y+step));
      res.emplace_back(Grid(x-step, y+step));
      res.emplace_back(Grid(x-step, y-step));
      res.emplace_back(Grid(x+step, y-step));
    }
    return res;
  }

  Grid &operator++() { y++; if (y >= W) x++, y=0; return *this; }
  bool operator==(const Grid &g) const { return x==g.x && y==g.y; }
  bool operator!=(const Grid &g) const { return x!=g.x || y!=g.y; }
  friend ostream &operator<<(ostream &os, const Grid &g) { return os << g.x << " " << g.y; }
  friend istream &operator>>(istream &is, Grid &g) {
    int a,b;
    is >> a >> b;
    g = Grid(a,b);
    return (is);
  }
};


int main() {
  cin >> H >> W;
  vector<string> G(H);
  rep(i,H) {
    cin >> G[i];
  }
  UnionFind uft(H*W);
  vector<Grid> R;
  mint res = 0;
  for (Grid g; g.isRange(); ++g) {
    if (G[g.x][g.y] == '.') {
      R.push_back(g);
      continue;
    }
    for (Grid h: g.newPos()) {
      if (h.isRange() && G[h.x][h.y] == '#')
        uft.unite(g.x*W+g.y, h.x*W+h.y);
    }
  }
  int c = 0;
  for (Grid g; g.isRange(); ++g) {
    if (G[g.x][g.y] == '.')
      continue;
    if (uft.root(g.x*W+g.y) == g.x*W+g.y)
      c++;
  }
  for (Grid g: R) {
    set<int> root;
    for (Grid h: g.newPos()) {
      if (h.isRange() && G[h.x][h.y] == '#')
        root.insert(uft.root(h.x*W+h.y));
    }
    res += c+1-root.size();
  }
  res /= R.size();
  print(res);
  return 0;
}