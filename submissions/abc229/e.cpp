#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


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
  int N,M;
  cin >> N >> M;
  vector<vector<int>> edge(N);
  vector<int> ans(N,0);
  rep(_,M) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    edge[a].push_back(b);
  }
  UnionFind uft(N);
  int component = 0;
  for (int i=N-1; i>=0; i--) {
    ans[i] = component;
    component++;
    for (int e: edge[i]) {
      if (!uft.same(i,e)) {
        component--;
        uft.unite(i,e);
      }
    }
  }
  rep(i,N) {
    print(ans[i]);
  }
  return 0;
}
