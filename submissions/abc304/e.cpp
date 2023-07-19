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


int main() {
  int N,M,K,Q;
  cin >> N >> M;
  UnionFind uft(N);
  rep(_,M) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    uft.unite(u,v);
  }
  set<pair<int,int>> bad;
  cin >> K;
  rep(i,K) {
    int x,y;
    cin >> x >> y;
    int rx = uft.root(--x), ry = uft.root(--y);
    assert(rx != ry);
    if (rx < ry)
      swap(rx, ry);
    bad.insert({rx, ry});
  }
  cin >> Q;
  rep(_,Q) {
    int p,q;
    cin >> p >> q;
    int rp = uft.root(--p), rq = uft.root(--q);
    if (rp < rq)
      swap(rp, rq);
    bool flag = true;
    if (bad.find({rp, rq}) != bad.end())
      flag = false;
    printyesno(flag);
  }
  return 0;
}
