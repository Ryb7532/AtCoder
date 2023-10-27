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

int H, W;
vector<int> dx = {-1,-1,-1,0,1,1,1,0}, dy = {1,0,-1,-1,-1,0,1,1};

pair<int,int> newPos(int x, int y, int id, int step=1) {
  return {x+step*dx[id], y+step*dy[id]};
}

bool isRange(int h, int w) {
  return h>=0 && h<H && w>=0 && w<W;
}


int main() {
  cin >> H >> W;
  vector<string> S(H);
  rep(i,H) {
    cin >> S[i];
  }
  map<pair<int,int>,int> ids;
  int n = 0;
  rep(i,H) {
    rep(j,W) {
      if (S[i][j] == '#')
        ids[{i,j}] = n++;
    }
  }
  UnionFind uft(n);
  rep(i,H) {
    rep(j,W) {
      if (S[i][j] != '#')
        continue;
      int id = ids[{i,j}];
      rep(k,8) {
        auto [h,w] = newPos(i,j,k);
        if (isRange(h,w) && S[h][w] == '#')
          uft.unite(id, ids[{h,w}]);
      }
    }
  }
  int res = 0;
  rep(i,n) {
    if (uft.root(i) == i)
      res++;
  }
  print(res);
  return 0;
}