#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"

struct Edge {
  int u;
  int v;
  ll w;
};
auto compare = [](auto const &lhs, auto const &rhs) {
  return lhs.w < rhs.w;
};


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
};


int main() {
  int N;
  cin >> N;
  vec<Edge> E(N-1);
  rep(i,N-1) {
    int u,v;
    cin >> u >> v >> E[i].w;
    u--; v--;
    E[i].u = u;
    E[i].v = v;
  }
  sort(all(E), compare);
  UnionFind uft(N);
  ll res = 0;
  rep(i,N-1) {
    int u,v;
    u = E[i].u;
    v = E[i].v;
    if (uft.same(u, v))
      continue;
    res += E[i].w * uft.size(u) * uft.size(v);
    uft.unite(u, v);
  }
  print(res);
  return 0;
}
