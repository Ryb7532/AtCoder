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
#define Yes "Yes"
#define No "No"
#define printyn(f) cout << ((f) ? Yes : No) << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}
void print() {cout << endl;}
template<typename Arg, typename... Args> void print(const Arg a, const Args... b) {
  cout << a;
  (cout << ... << (cout << ' ', b)) << endl;
}

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
  int Y;
  cin >> H >> W >> Y;
  vector<vector<int>> A(H+2,vector<int>(W+2));
  vector<vector<int>> state(H+2, vector<int>(W+2, -1));
  map<int, vector<Grid>> id;
  int res = H*W;
  rep(i,H) {
    rep(j,W) {
      int a;
      cin >> a;
      A[i+1][j+1] = a;
      id[a].push_back(Grid(i+1,j+1));
      state[i+1][j+1] = 1;
    }
  }
  if (id.find(Y+1) == id.end())
    id[Y+1] = vector<Grid>();
  int h = 1;
  fore(e, id) {
    rep(i,h,min(e.first,Y+1)) {
      print(res);
    }
    queue<Grid> q;
    fore(p,e.second) {
      state[p.x()][p.y()] = 0;
      bool f = false;
      fore(n,p.newPos()) {
        if (state[n.x()][n.y()] == -1)
          f = true;
      }
      if (f)
        q.push(p);
    }
    while (!q.empty()) {
      Grid p = q.front();
      q.pop();
      if (state[p.x()][p.y()] == -1)
        continue;
      state[p.x()][p.y()] = -1;
      res--;
      fore(n, p.newPos()) {
        if (state[n.x()][n.y()] == 0) {
          q.push(n);
        }
      }
    }
    h = e.first;
  }
  return 0;
}