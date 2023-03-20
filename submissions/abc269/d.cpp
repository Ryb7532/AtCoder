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
  vector<int> X(N), Y(N);
  rep(i,N) {
    cin >> X[i] >> Y[i];
  }
  UnionFind uft(N);
  rep(i,N) {
    rep(j,N) {
      if (i == j)
        continue;
      int dx = X[i]-X[j], dy = Y[i]-Y[j];
      if ((abs(dx) <= 1 && dy == 0) || (dx == 0 && abs(dy) <= 1) || (dx == dy && abs(dx) <= 1))
        uft.unite(i,j);
    }
  }
  int res = 0;
  rep(i,N) {
    if (uft.root(i) == i)
      res++;
  }
  print(res);
  return 0;
}
