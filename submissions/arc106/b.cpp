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
  int N,M;
  cin >> N >> M;
  vec<ll> a(N),b(N);
  rep(i,N) {
    cin >> a[i];
  }
  rep(i,N) {
    cin >> b[i];
  }
  UnionFind uft(N);
  rep(i,M) {
    int c,d;
    cin >> c >> d;
    c--; d--;
    uft.unite(c,d);
  }
  map<int,ll> m;
  rep(i,N) {
    m[uft.root(i)] += a[i]-b[i];
  }
  for (auto &e: m) {
    if (m[e.first] != 0) {
      print(No);
      return 0;
    }
  }
  print(Yes);
  return 0;
}
