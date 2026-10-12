#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep1(n) rep2(_,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define printyn(f) cout << ((f) ? "Yes" : "No") << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}
void print() {cout << endl;}
template<typename Arg, typename... Args> void print(const Arg a, const Args... b) {
  cout << a;
  (cout << ... << (cout << ' ', b)) << endl;
}
template<class... T> void scan(T&... a) {(cin >> ... >> a);}


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
  int N,M,K;
  scan(N,M,K);
  vector<int> u(M), v(M), idx(M);
  vector<ll> w(M);
  vector<pair<int,int>> C(N, {0,0});
  rep(i,M) {
    scan(u[i], v[i], w[i]);
    u[i]--; v[i]--;
    idx[i] = i;
  }
  rep(i,K) {
    int a;
    scan(a);
    a--;
    C[a].first++;
  }
  rep(i,K) {
    int b;
    scan(b);
    b--;
    C[b].second++;
  }
  sort(all(idx), [&](int a, int b) { return w[a] < w[b]; });
  UnionFind uft(N);
  ll res = 0;
  fore(i,idx) {
    if (uft.same(u[i], v[i])) continue;
    int ru = uft.root(u[i]), rv = uft.root(v[i]);
    auto cu = C[ru], cv = C[rv];
    uft.unite(u[i], v[i]);
    int r = uft.root(u[i]);
    C[r] = {cu.first + cv.first, cu.second + cv.second};
    int match = min(C[r].first, C[r].second);
    res += match * w[i];
    C[r].first -= match;
    C[r].second -= match;
  }
  print(res);
  return 0;
}