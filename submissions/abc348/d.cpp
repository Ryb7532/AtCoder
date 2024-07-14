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
  vector<string> A(H);
  Grid s,t;
  rep(i,H) {
    cin >> A[i];
    rep(j,W) {
      if (A[i][j] == 'S')
        s = {i,j};
      if (A[i][j] == 'T')
        t = {i,j};
    }
  }
  int N;
  map<Grid, int> med;
  cin >> N;
  rep(i,N) {
    Grid g;
    int e;
    cin >> g >> e;
    med[g] = e;
  }
  priority_queue<pair<int,Grid>> q;
  vector<vector<int>> C(H, vector<int>(W, -1));
  C[s.x()][s.y()] = med[s];
  q.push({C[s.x()][s.y()], s});
  while (!q.empty()) {
    auto top = q.top();
    int c = top.first;
    Grid g = top.second;
    q.pop();
    if (c < C[g.x()][g.y()] || c == 0)
      continue;
    fore(h, g.newPos()) {
      if (!h.isRange() || A[h.x()][h.y()] == '#')
        continue;
      if (C[h.x()][h.y()] < max(c-1, med[h])) {
        C[h.x()][h.y()] = max(c-1, med[h]);
        q.push({C[h.x()][h.y()], h});
      }
    }
  }
  printyn(C[t.x()][t.y()] >= 0);
  return 0;
}