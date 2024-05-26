#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

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
