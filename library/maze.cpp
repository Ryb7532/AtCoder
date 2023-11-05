#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)


int H, W;
int dx4[] = {-1,0,1,0}, dy4[] = {0,-1,0,1};
int dx8[] = {-1,-1,-1,0,1,1,1,0}, dy8[] = {1,0,-1,-1,-1,0,1,1};
struct Grid {
  int x;
  int y;
  Grid(int x=0, int y=0) : x(x), y(y) {}

  bool isRange() { return 0<=x && x<H && 0<=y && y<W; }

  vector<Grid> newPos(int step=1) {
    vector<Grid> res;
    rep(i,4) {
      res.emplace_back(Grid(x+step*dx4[i], y+step*dy4[i]));
    }
    return res;
  }

  vector<Grid> newPos_8(int step=1) {
    vector<Grid> res;
    rep(i,8) {
      res.emplace_back(Grid(x+step*dx8[i], y+step*dy8[i]));
    }
    return res;
  }

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
