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
  ll sx, sy, tx, ty;
  cin >> N >> sx >> sy >> tx >> ty;
  vector<ll> X(N),Y(N),R(N);
  rep(i,N) {
    cin >> X[i] >> Y[i] >> R[i];
  }
  UnionFind uft(N+2);
  rep(i,N) {
    rep(j,N) {
      ll x = X[i] - X[j];
      ll y = Y[i] - Y[j];
      ll r0 = R[i] + R[j];
      ll r1 = R[i] - R[j];
      if (x * x + y * y <= r0 * r0 && x * x + y * y >= r1 * r1)
        uft.unite(i, j);
    }
    {
      ll x = X[i] - sx;
      ll y = Y[i] - sy;
      if (x * x + y * y == R[i] * R[i])
        uft.unite(i, N);
    }
    {
      ll x = X[i] - tx;
      ll y = Y[i] - ty;
      if (x * x + y * y == R[i] * R[i])
        uft.unite(i, N+1);
    }
  }
  print((uft.same(N, N+1) ? Yes : No));
  return 0;
}
