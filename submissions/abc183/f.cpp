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
  vec<int> par;
  UnionFind(int n) : par(n,-1) {}

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
  int N,Q;
  cin >> N >> Q;
  vec<int> C(N);
  vec<map<int,int>> m(N);
  rep(i,N) {
    cin >> C[i];
    C[i]--;
    m[i][C[i]]++;
  }
  UnionFind uft(N);
  rep(i,Q) {
    int q,a,b;
    cin >> q >> a >> b;
    a--;
    b--;
    if (q==1 && !uft.same(a,b)) {
      int ra = uft.root(a), rb = uft.root(b);
      if (uft.par[ra]>uft.par[rb])
        swap(ra,rb);
      for (auto &e : m[rb]) {
        m[ra][e.first] += e.second;
      }
      uft.unite(ra,rb);
    } else if (q == 2) {
      int ra = uft.root(a);
      print(m[ra][b]);
    }
  }
  return 0;
}
