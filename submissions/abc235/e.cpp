#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
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
  int N,M,Q;
  cin >> N >> M >> Q;
  vector<pair<int,int>> ab(M),c(M), uv(Q), w(Q);
  vector<bool> res(Q);
  rep(i,M) {
    int a,b;
    cin >> a >> b >> c[i].first;
    ab[i] = {--a,--b};
    c[i].second = i;
  }
  rep(i,Q) {
    int u,v;
    cin >> u >> v >> w[i].first;
    uv[i] = {--u,--v};
    w[i].second = i;
  }
  sort(all(c));
  sort(all(w));
  int i=0,j=0;
  UnionFind uft(N);
  while (i<M) {
    while (j<Q && c[i].first > w[j].first) {
      int k = w[j].second;
      res[k] = !uft.same(uv[k].first, uv[k].second);
      j++;
    }
    int k = c[i].second;
    uft.unite(ab[k].first, ab[k].second);
    i++;
  }
  rep(i,Q) {
    print((res[i] ? Yes : No));
  }
  return 0;
}
