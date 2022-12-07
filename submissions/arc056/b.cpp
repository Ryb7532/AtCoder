#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
UnionFind uft(200000);

set<int, greater<int>> s[200000];
bool ans[200000];

int main() {
  int N, M, S, u, v;
  cin >> N >> M >> S;
  S--;
  rep(i,M) {
    cin >> u >> v;
    u--; v--;
    s[u].insert(v);
    s[v].insert(u);
  }
  repr(i,N,0) {
    for (auto &e: s[i]) {
      if (i<e)
        uft.unite(e,i);
    }
    if (uft.same(S,i)) {
      ans[i] = true;
    } else {
      ans[i] = false;
    }
  }
  rep(i,N) {
    if (ans[i])
      print(i+1);
  }
  return 0;
}
