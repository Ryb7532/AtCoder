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
  int N,Q;
  scan(N,Q);
  UnionFind uf(N);
  vector<vector<int>> top10(N, vector<int>(10, -1));
  rep(i,N) {
    top10[i][0] = i+1;
  }
  rep(Q) {
    int t,u,v;
    scan(t,u,v);
    u--; v--;
    if (t == 1) {
      int ru = uf.root(u), rv = uf.root(v);
      if (ru == rv) continue;
      uf.unite(u,v);
      int r = uf.root(u);
      vector<int> merged(10);
      int iu = 0, iv = 0;
      rep(i,10) {
        if (top10[ru][iu] > top10[rv][iv]) {
          merged[i] = top10[ru][iu];
          iu++;
        } else {
          merged[i] = top10[rv][iv];
          iv++;
        }
      }
      rep(i,10) {
        top10[r][i] = merged[i];
      }
    } else {
      int r = uf.root(u);
      print(top10[r][v]);
    }
  }
  return 0;
}