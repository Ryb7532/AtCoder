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
#define rrep1(n) rrep2(_,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define out1(a) cout << a << endl
#define out2(a,b) cout << a << " " << b << endl
#define out3(a,b,c) cout << a << " " << b << " " << c << endl
#define print(...) GET_MACRO(__VA_ARGS__,out3,out2,out1)(__VA_ARGS__)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyn(f) cout << (f ? Yes : No) << endl
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
  cin >> N >> M;
  vector<int> A(N);
  vector<pair<int,int>> UV;
  UnionFind uft(N);
  vector<vector<int>> E(N);
  rep(i,N) {
    cin >> A[i];
  }
  rep(M) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    if (A[u] > A[v])
      swap(u,v);
    if (A[u] == A[v])
      uft.unite(u,v);
    else
      UV.push_back({u,v});
  }
  fore(e,UV) {
    E[uft.root(e.first)].push_back(uft.root(e.second));
  }
  vector<int> dp(N,0);
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
  vector<bool> seen(N,false);
  dp[uft.root(0)] = 1;
  q.push({A[0],uft.root(0)});
  seen[uft.root(0)] = true;
  while (!q.empty()) {
    auto top = q.top();
    q.pop();
    int n = top.second;
    fore(e, E[n]) {
      if (!seen[e]) {
        dp[e] = dp[n]+1;
        q.push({A[e], e});
        seen[e] = true;
      } else {
        chmax(dp[e], dp[n]+1);
      }
    }
  }
  print(dp[uft.root(N-1)]);
  return 0;
}