#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


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


int main() {
  vector<vector<bool>> A(6, vector<bool>(6, false));
  rep(i,4) {
    rep(j,4) {
      int a;
      cin >> a;
      A[i+1][j+1] = a==1;
    }
  }
  vector<int> dx = {1,0,-1,0}, dy = {0,1,0,-1};
  int res = 0;
  rep(k,1<<16) {
    vector<vector<bool>> B(6, vector<bool>(6, false));
    rep(i,4) {
      rep(j,4) {
        B[i+1][j+1] = (k&(1<<(i*4+j)))!= 0;
      }
    }
    bool flag = true;
    rep(i,6) {
      rep(j,6) {
        if (A[i][j] && !B[i][j])
          flag = false;
      }
    }
    UnionFind uft(36);
    rep(i,6) {
      rep(j,6) {
        rep(l,4) {
          int x = i+dx[l], y = j+dy[l];
          if (x < 0 || x >= 6 || y < 0 || y >= 6)
            continue;
          if (B[i][j] == B[x][y])
            uft.unite(i*6+j, x*6+y);
        }
      }
    }
    int region = 0;
    rep(i,36) {
      if (uft.root(i) == i)
        region++;
    }
    if (region > 2)
      flag = false;
    if (flag)
      res++;
  }
  print(res);
  return 0;
}
