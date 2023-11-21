#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i=(int)n-1; i>=0; i--)

template<typename data_t, typename sum_t>
class ReRooting {
private:
  struct Edge { int to; data_t data; sum_t dp, ndp; };
  // Function to merge data
  using F = function<sum_t(sum_t,sum_t)>;
  // Function to calculate the value of the subtree
  using G = function<sum_t(sum_t,data_t)>;

  vector<vector<Edge>> g;
  vector<sum_t> subdp, dp;
  const F f1;
  const G f2;
  const sum_t ident;

  void dfs_sub(int n, int p) {
    for (auto &e: g[n]) {
      if (e.to == p)
        continue;
      dfs_sub(e.to, n);
      subdp[n] = f1(subdp[n], f2(subdp[e.to], e.data));
    }
  }

  void dfs_all(int n, int p, const sum_t &top) {
    sum_t buff{ident};
    rep(i,g[n].size()) {
      auto &e = g[n][i];
      e.ndp = buff;
      e.dp = f2(p == e.to ? top : subdp[e.to], e.data);
      buff = f1(buff, e.dp);
    }
    dp[n] = buff;
    buff = ident;
    rrep(i,g[n].size()) {
      auto &e = g[n][i];
      if(e.to != p)
        dfs_all(e.to, n, f1(e.ndp, buff));
      e.ndp = f1(e.ndp, buff);
      buff = f1(buff, e.dp);
    }
  }

public:
  ReRooting(int n, const F &f1, const G &f2, const sum_t &ident) :
    g(n), f1(f1), f2(f2), ident(ident), subdp(n, ident), dp(n, ident) {}

  void add_edge(int u, int v, const data_t &d) {
    g[u].emplace_back((Edge){v, d, ident, ident});
    g[v].emplace_back((Edge){u, d, ident, ident});
  }

  void add_edge_bi(int u, int v, const data_t &d, const data_t &e) {
    g[u].emplace_back((Edge){v, d, ident, ident});
    g[v].emplace_back((Edge){u, e, ident, ident});
  }

  void solve() {
    dfs_sub(0,-1);
    dfs_all(0,-1,ident);
  }

  sum_t &operator[](const int i) { return dp[i]; }
};
