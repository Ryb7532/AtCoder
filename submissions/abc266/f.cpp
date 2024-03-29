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
  int N;
  cin >> N;
  vector<vector<int>> E(N);
  vector<int> D(N,0);
  rep(i,N) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
    D[u]++;
    D[v]++;
  }
  UnionFind uft(N);
  queue<int> d1;
  rep(i,N) {
    if (D[i] == 1)
      d1.push(i);
  }
  while (!d1.empty()) {
    int n = d1.front();
    d1.pop();
    for (auto m: E[n]) {
      if (D[m] == 0)
        continue;
      D[m]--;
      uft.unite(n,m);
      if (D[m] == 1)
        d1.push(m);
    }
  }
  int Q;
  cin >> Q;
  rep(_,Q) {
    int x,y;
    cin >> x >> y;
    x--; y--;
    print((uft.same(x,y) ? Yes : No));
  }
  return 0;
}
