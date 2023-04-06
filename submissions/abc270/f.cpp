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
  int N,M;
  cin >> N >> M;
  vector<pair<ll,int>> X(N), Y(N);
  rep(i,N) {
    ll x;
    cin >> x;
    X[i] = {x, i};
  }
  rep(i,N) {
    ll y;
    cin >> y;
    Y[i] = {y, i};
  }
  vector<pair<ll, pair<int,int>>> E(M);
  rep(i,M) {
    int a,b;
    ll z;
    cin >> a >> b >> z;
    E[i] = {z, {--a, --b}};
  }
  sort(all(X));
  sort(all(Y));
  sort(all(E));
  const ll INF = 1e18;
  ll res = INF;
  rep(j,4) {
    UnionFind uft(N);
    ll r = 0;
    int ix = N, iy = N, ie = 0;
    if (j & 1) {
      r += X[0].first;
      ix = 1;
    }
    if (j & 2) {
      r += Y[0].first;
      iy = 1;
    }
    while (ix < N || iy < N || ie < M) {
      ll xmin = INF, ymin = INF, emin = INF;
      int xu=X[0].second, xv=N, yu=Y[0].second, yv=N, eu=N, ev=N;
      if (ix < N) {
        xmin = X[ix].first;
        xv = X[ix].second;
      }
      if (iy < N) {
        ymin = Y[iy].first;
        yv = Y[iy].second;
      }
      if (ie < M) {
        emin = E[ie].first;
        eu = E[ie].second.first;
        ev = E[ie].second.second;
      }
      if (xmin < ymin && xmin < emin) {
        if (!uft.same(xu, xv)) {
          r += xmin;
          uft.unite(xu, xv);
        }
        ix++;
      } else if (ymin < emin) {
        if (!uft.same(yu, yv)) {
          r += ymin;
          uft.unite(yu, yv);
        }
        iy++;
      } else {
        if (!uft.same(eu, ev)) {
          r += emin;
          uft.unite(eu, ev);
        }
        ie++;
      }
    }
    if (uft.size(0) == N)
      res = min(res, r);
  }
  print(res);
  return 0;
}
