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
  int N;
  cin >> N;
  vector<pair<int,int>> P(N);
  vector<int> idX(1e5,-1), idY(1e5,-1);
  UnionFind uftX(1e5),uftY(1e5), uft(N);
  rep(i,N) {
    int x,y;
    cin >> x >> y;
    x--; y--;
    P[i] = {x,y};
    if (idX[x] == -1) {
      idX[x] = i;
    } else {
      uftY.unite(y,P[idX[x]].second);
      uft.unite(i, idX[x]);
    }
    if (idY[y] == -1) {
      idY[y] = i;
    } else {
      uftX.unite(x,P[idY[y]].first);
      uft.unite(i, idY[y]);
    }
  }
  ll res = 0;
  rep(i,N) {
    if (i == uft.root(i)) {
      ll x = uftX.size(P[i].first);
      ll y = uftY.size(P[i].second);
      res += x*y;
      res -= uft.size(i);
    }
  }
  print(res);
  return 0;
}
