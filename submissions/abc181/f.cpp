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
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
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
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  vector<pair<int,pair<int,int>>> dist;
  rep(i,N) {
    cin >> X[i] >> Y[i];
    dist.push_back({(100-Y[i])*(100-Y[i]), {0,i+1}});
    rep(j,i) {
      int x = X[i]-X[j];
      int y = Y[i]-Y[j];
      int d = x*x+y*y;
      dist.push_back({d, {j+1,i+1}});
    }
    dist.push_back({(Y[i]+100)*(Y[i]+100), {N+1,i+1}});
  }
  sort(all(dist));
  int res = 0;
  UnionFind uft(N+2);
  for (auto [d,p]: dist) {
    uft.unite(p.first, p.second);
    if (uft.same(0,N+1)) {
      res = d;
      break;
    }
  }
  print(fix(10) << sqrt(res)/2);
  return 0;
}