#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


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


int main() {
  ll N, M, D;
  cin >> N >> M >> D;
  int l[N], a, d[N];
  rep(i,N)
    l[i] = i;
  rep(i,M) {
    cin >> a;
    swap(l[a-1], l[a]);
  }
  rep(i,N) {
    d[l[i]] = i;
  }
  UnionFind uft(N);
  bool used[N];
  int ans[N];
  fill(used, used+N, false);
  rep(i,N) {
    uft.unite(i,d[i]);
  }
  rep(i,N) {
    if (used[i])
      continue;
    int a, b, c;
    a = b = i;
    c = D%uft.size(i);
    while (!used[a]) {
      if (c == 0) {
        ans[a] = b;
        used[a] = true;
        b = d[b];
        a = d[a];
      } else {
        c--;
        b = d[b];
      }
    }
  }
  rep(i,N) {
    print(ans[i]+1);
  }
  return 0;
}
