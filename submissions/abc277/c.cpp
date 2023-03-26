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
  map<int,int> toid;
  toid[1] = 0;
  int id = 0;
  vector<int> A(N), B(N);
  UnionFind uft(2*N+1);
  rep(i,N) {
    cin >> A[i] >> B[i];
    if (toid.find(A[i]) == toid.end())
      toid[A[i]] = ++id;
    if (toid.find(B[i]) == toid.end())
      toid[B[i]] = ++id;
    uft.unite(toid[A[i]], toid[B[i]]);
  }
  int res = 0;
  for (auto e: toid) {
    if (uft.same(0, e.second)) {
      res = max(res, e.first);
    }
  }
  print(res);
  return 0;
}
