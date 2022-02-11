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
  int N,M;
  cin >> N;
  vector<pair<int,int>> E(N-1), S(M);
  rep(i,N-1) {
    int a,b;
    cin >> a >> b;
    E[i] = {--a,--b};
  }
  cin >> M;
  rep(i,M) {
    int u,v;
    cin >> u >> v;
    S[i] = {--u,--v};
  }
  vector<int> involve(N-1,0);
  rep(i,N-1) {
    UnionFind uft(N);
    rep(j,N-1) {
      if (j==i)
        continue;
      uft.unite(E[j].first, E[j].second);
    }
    rep(j,M) {
      if (!uft.same(S[j].first, S[j].second))
        involve[i] += 1 << j;
    }
  }
  vector<vector<ll>> dp(N, vector<ll>(1<<M,0));
  dp[0][0] = 1;
  rep(i,N-1) {
    rep(j,1<<M) {
      dp[i+1][j] += dp[i][j];
      dp[i+1][j|involve[i]] += dp[i][j];
    }
  }
  print(dp[N-1][(1<<M)-1]);
  return 0;
}
