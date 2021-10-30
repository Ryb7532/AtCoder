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
  int &operator[](const int i) { return par[i]; }
};


int main() {
  int N,M;
  cin >> N >> M;
  UnionFind uft(N);
  int component = N;
  vec<pair<int, int>> E(M);
  set<pair<ll, int>> cost;
  ll res = 0;
  rep(i,M) {
    int A,B;
    ll C;
    cin >> A >> B >> C;
    A--; B--;
    E[i] = {A,B};
    if (C < 0) {
      if (!uft.same(A,B)) {
        component--;
        uft.unite(A,B);
      }
    } else {
      cost.insert({C, i});
    }
  }
  while(!cost.empty()) {
    auto t = cost.begin();
    cost.erase(t);
    auto e = E[(*t).second];
    int a = e.first, b = e.second;
    if (!uft.same(a,b)) {
      component--;
      uft.unite(a,b);
    } else {
      res += (*t).first;
    }
  }
  print(res);
  return 0;
}
