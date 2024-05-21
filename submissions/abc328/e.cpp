#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

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
  int N,M;
  ll K;
  cin >> N >> M >> K;
  vector<int> u(M), v(M);
  vector<ll> w(M);
  rep(i,M) {
    cin >> u[i] >> v[i] >> w[i];
    u[i]--;
    v[i]--;
  }
  UnionFind uft(N);
  int pat = 0;
  ll res = 1e18;
  rep(_,N-1) {
    pat <<= 1;
    pat++;
  }
  while (pat < (1<<M)) {
    uft.par.assign(N,-1);
    ll tmp = 0;
    rep(i,M) {
      if (pat & (1<<i)) {
        uft.unite(u[i],v[i]);
        tmp += w[i];
        tmp %= K;
      }
    }
    int root = uft.root(0);
    if (uft[root] == -N)
      chmin(res,tmp);
    int a = 0, b = 0;
    while ((pat&(1<<a)) == 0)
      a++;
    while ((pat&(1<<(a+b))))
      b++;
    pat += 1<<a;
    rep(i,b-1)
      pat += 1<<i;
  }
  print(res);
  return 0;
}