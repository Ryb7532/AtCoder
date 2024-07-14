#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

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
