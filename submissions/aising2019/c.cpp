#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
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

int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};

int main() {
  int H,W;
  cin >> H >> W;
  vector<string> S(H);
  rep(i,H) {
    cin >> S[i];
  }
  UnionFind uft(H*W);
  ll res = 0;
  rep(i,H) {
    rep(j,W) {
      rep(k,4) {
        int h = i+dy[k], w = j+dx[k];
        if (h < 0 || h >= H || w < 0 || w >= W || S[i][j] == S[h][w])
          continue;
        uft.unite(i*W+j, h*W+w);
      }
    }
  }
  vector<vector<ll>> cnt(H*W, vector<ll>(2,0));
  rep(i,H) {
    rep(j,W) {
      int root = uft.root(i*W+j);
      cnt[root][S[i][j] == '.']++;
    }
  }
  rep(i,H*W) {
    res += cnt[i][0]*cnt[i][1];
  }
  print(res);
  return 0;
}
