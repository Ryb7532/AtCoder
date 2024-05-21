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
  int N,Q;
  cin >> N >> Q;
  vector<int> a(Q), b(Q);
  vector<ll> d(Q);
  vector<vector<pair<int,ll>>> E(N);
  UnionFind uft(N);
  vector<bool> used(Q,false);
  rep(i,Q) {
    cin >> a[i] >> b[i] >> d[i];
    a[i]--, b[i]--;
    if (!uft.same(a[i], b[i])) {
      uft.unite(a[i],b[i]);
      E[a[i]].push_back({b[i],-d[i]});
      E[b[i]].push_back({a[i],d[i]});
      used[i] = true;
    }
  }
  vector<ll> X(N);
  vector<bool> seen(N,false);
  rep(i,N) {
    int r = uft.root(i);
    if (r != i)
      continue;
    X[r] = 0;
    seen[r] = true;
    queue<int> q;
    q.push(r);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      fore(e,E[u]) {
        int v = e.first;
        ll d = e.second;
        if (seen[v])
          continue;
        X[v] = X[u]+d;
        seen[v] = true;
        q.push(v);
      }
    }
  }
  rep(i,Q) {
    if (X[a[i]]-X[b[i]] == d[i])
      cout << i+1 << " ";
  }
  cout << endl;
  return 0;
}