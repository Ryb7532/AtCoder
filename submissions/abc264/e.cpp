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
#define YES "YES"
#define No "No"
#define NO "NO"


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
  int N,M,E,Q;
  cin >> N >> M >> E;
  vector<pair<int,int>> edge(E);
  rep(i,E) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    edge[i] = {u,v};
  }
  cin >> Q;
  vector<int> query(Q);
  vector<bool> connect(E, true);
  rep(i,Q) {
    int q;
    cin >> q;
    q--;
    query[i] = q;
    connect[q] = false;
  }
  UnionFind uft(N+M);
  set<int> used;
  rep(i,E) {
    if (connect[i])
      uft.unite(edge[i].first, edge[i].second);
  }
  int cnt = 0;
  vector<int> res(Q);
  rep(i,M) {
    int r = uft.root(N+i);
    if (used.find(r) == used.end()) {
      cnt += uft.size(r);
      used.insert(r);
    }
  }
  cnt -= M;
  res[Q-1] = cnt;
  rep(i,Q-1) {
    int q = query[Q-1-i];
    int u,v;
    u = edge[q].first;
    v = edge[q].second;
    int ru,rv;
    ru = uft.root(u);
    rv = uft.root(v);
    bool cu, cv;
    cu = used.find(ru) != used.end();
    cv = used.find(rv) != used.end();
    if (cu && !cv) {
      cnt += uft.size(v);
    }
    if (!cu && cv) {
      cnt += uft.size(u);
    }
    uft.unite(u,v);
    if (cu || cv)
      used.insert(uft.root(u));
    res[Q-2-i] = cnt;
  }
  rep(i,Q) {
    print(res[i]);
  }
  return 0;
}
