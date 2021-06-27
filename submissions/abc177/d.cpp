#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << a << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

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


int main() {
  int N,M;
  cin >> N >> M;
  rep(i,M) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    uft.unite(a,b);
  }
  int Max = 0;
  rep(i,N) {
    Max = max(Max,uft.size(i));
  }
  print(Max);
  return 0;
}
