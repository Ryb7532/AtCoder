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
  int K;
  cin >> H >> W >> K;
  vector<string> S(H+1);
  rep(i,H) {
    cin >> S[i];
    S[i].push_back('x');
  }
  rep(j,W) {
    S[H].push_back('x');
  }
  int res = 1e9;
  queue<char> q;
  rep(i,H) {
    int cnt = 0, change = 0;
    rep(j,W+1) {
      if (S[i][j] == 'x') {
        cnt = 0;
        change = 0;
        while (!q.empty())
          q.pop();
      } else {
        cnt++;
        if (S[i][j] == '.')
          change++;
        q.push(S[i][j]);
        if (cnt == K) {
          chmin(res, change);
          char top = q.front();
          q.pop();
          cnt--;
          if (top == '.')
            change--;
        }
      }
    }
  }
  rep(j,W) {
    int cnt = 0, change = 0;
    rep(i,H+1) {
      if (S[i][j] == 'x') {
        cnt = 0;
        change = 0;
        while (!q.empty())
          q.pop();
      } else {
        cnt++;
        if (S[i][j] == '.')
          change++;
        q.push(S[i][j]);
        if (cnt == K) {
          chmin(res, change);
          char top = q.front();
          q.pop();
          cnt--;
          if (top == '.')
            change--;
        }
      }
    }
  }
  if (res == 1e9)
    res = -1;
  print(res);
  return 0;
}