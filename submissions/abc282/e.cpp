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
  ll M;
  cin >> N >> M;
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  vector<pair<int,pair<int,int>>> point;
  rep(i,N) {
    rep(j,N-i-1) {
      ll x0, x1, y0, y1, a0=1, a1=1;
      x0 = x1 = A[i];
      y0 = y1 = A[j+i+1];
      while (y0 != 0) {
        a0 *= (y0 & 1) ? x0 : 1;
        x0 *= x0;
        y0 >>= 1;
        a0 %= M;
        x0 %= M;
      }
      while (x1 != 0) {
        a1 *= (x1 & 1) ? y1 : 1;
        y1 *= y1;
        x1 >>= 1;
        a1 %= M;
        y1 %= M;
      }
      ll a = (a0 + a1) % M;
      point.push_back({a,{i,j+i+1}});
    }
  }
  sort(rall(point));
  UnionFind UFT(N);
  int num_edge = N-1;
  int i = 0;
  ll res = 0;
  while (num_edge != 0) {
    auto top = point[i];
    ll p = top.first;
    int s = top.second.first, t = top.second.second;
    if (!UFT.same(s, t)) {
      res += p;
      UFT.unite(s, t);
      num_edge--;
    }
    i++;
  }
  print(res);
  return 0;
}
