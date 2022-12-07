#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())

struct UnionFind {
  vector<int> par;
  UnionFind(int n) : par(n) { par.assign(n, -1); }

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
    if (par[a]>par[b])
      swap(a, b);
    par[ra] += par[rb];
    par[rb] = ra;
    return;
  }
  bool same(int a, int b) {
    int ra = root(a), rb = root(b);
    return ra == rb;
  }
};
UnionFind uft(100);


int main() {
  int N,M;
  cin >> N >> M;
  vector<bool> tree(N,true);
  rep(i,M) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    if (uft.same(u,v)) {
      tree[u] = tree[v] = false;
      continue;
    }
    uft.unite(u,v);
  }
  set<int> p;
  rep(i,N) {
    p.insert(uft.root(i));
  }
  rep(i,N) {
    if (!tree[i]) {
      p.erase(uft.root(i));
    }
  }
  print(p.size());
  return 0;
}
