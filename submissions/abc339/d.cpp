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
#define rrep1(n) rrep2(_,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)
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
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

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

  int id() {
    return x*W+y;
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
  int N;
  cin >> N;
  string S;
  H = N;
  W = N;
  vector<vector<int>> dp(N*N, vector<int>(N*N, 1e9));
  vector<Grid> P;
  queue<pair<Grid, Grid>> q;
  rep(i,N) {
    string s;
    cin >> s;
    S += s;
  }
  rep(i,N*N) {
    if (S[i] == 'P')
      P.emplace_back(i/N, i%N);
  }
  dp[P[0].id()][P[1].id()] = 0;
  q.push({P[0], P[1]});
  while (!q.empty()) {
    auto top = q.front();
    q.pop();
    auto [p0, p1] = top;
    auto v0 = p0.newPos();
    auto v1 = p1.newPos();
    rep(i,4) {
      auto np0 = v0[i];
      auto np1 = v1[i];
      if (!np0.isRange() || S[np0.id()] == '#')
        np0 = p0;
      if (!np1.isRange() || S[np1.id()] == '#')
        np1 = p1;
      if (dp[np0.id()][np1.id()] > dp[p0.id()][p1.id()]+1) {
        dp[np0.id()][np1.id()] = dp[p0.id()][p1.id()]+1;
        q.push({np0, np1});
      }
    }
  }
  int res = 1e9;
  rep(i,N*N) {
    chmin(res, dp[i][i]);
  }
  if (res == 1e9)
    res = -1;
  print(res);
  return 0;
}