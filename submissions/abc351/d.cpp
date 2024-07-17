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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define out1(a) cout << (a) << endl
#define out2(a,b) cout << (a) << " " << (b) << endl
#define out3(a,b,c) cout << (a) << " " << (b) << " " << (c) << endl
#define print(...) GET_MACRO(__VA_ARGS__,out3,out2,out1)(__VA_ARGS__)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyn(f) cout << (f ? Yes : No) << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}

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
struct Grid: pair<int,int> {
  inline int &x() { return first; }
  inline int &y() { return second; }
  Grid(int x=0, int y=0) { first=x, second=y; }
  Grid(const pair<int,int> p) { first=p.first, second=p.second; }

  Grid &operator+=(const pair<int,int> &p) {
    x() += p.first;
    y() += p.second;
    return *this;
  }
  Grid &operator-=(const pair<int,int> &p) {
    x() -= p.first;
    y() -= p.second;
    return *this;
  }
  Grid operator+(const pair<int,int> &p) const { return Grid(*this) += p; }
  Grid operator-(const pair<int,int> &p) const { return Grid(*this) -= p; }
  Grid &operator++() { x()++; if (y() >= W) x()++, y()=0; return *this; }
  friend ostream &operator<<(ostream &os, const Grid &g) { return os << g.first << " " << g.second; }
  friend istream &operator>>(istream &is, Grid &g) {
    int a,b;
    is >> a >> b;
    a--; b--;
    g = Grid(a,b);
    return (is);
  }

  bool isRange() { return 0<=x() && x()<H && 0<=y() && y()<W; }

  vector<Grid> newPos(int step=1, bool dia=false) {
    vector<Grid> res;
    res.emplace_back(Grid(x()+step, y()));
    res.emplace_back(Grid(x(),      y()+step));
    res.emplace_back(Grid(x()-step, y()));
    res.emplace_back(Grid(x(),      y()-step));
    if (dia) {
      res.emplace_back(Grid(x()+step, y()+step));
      res.emplace_back(Grid(x()-step, y()+step));
      res.emplace_back(Grid(x()-step, y()-step));
      res.emplace_back(Grid(x()+step, y()-step));
    }
    return res;
  }
};

int main() {
  cin >> H >> W;
  vector<string> S(H);
  set<Grid> C;
  rep(i,H) {
    cin >> S[i];
  }
  rep(i,H) {
    rep(j,W) {
      if (S[i][j] != '#')
        continue;
      fore(n, Grid(i,j).newPos()) {
        if (!n.isRange())
          continue;
        if (S[n.x()][n.y()] != '#')
          C.insert(n);
      }
    }
  }
  UnionFind uft(H*W);
  rep(i,H) {
    rep(j,W) {
      if (S[i][j] == '#' || C.find(Grid(i,j)) != C.end())
        continue;
      fore(n, Grid(i,j).newPos()) {
        if (!n.isRange() || C.find(n) != C.end())
          continue;
        uft.unite(i*W+j, n.x()*W+n.y());
      }
    }
  }
  vector<int> cnt(H*W,0);
  rep(i,H) {
    rep(j,W) {
      if (S[i][j] == '#')
        continue;
      cnt[i*W+j] += uft.size(i*W+j);
      if (C.find(Grid(i,j)) != C.end()) {
        set<int> used;
        fore(n, Grid(i,j).newPos()) {
          if (!n.isRange() || S[n.x()][n.y()] == '#' || C.find(n) != C.end())
            continue;
          int root = uft.root(n.x()*W+n.y());
          if (used.find(root) == used.end()) {
            cnt[root]++;
            used.insert(root);
          }
        }
      }
    }
  }
  int res = 0;
  rep(i,H*W) {
    chmax(res, cnt[i]);
  }
  print(res);
  return 0;
}