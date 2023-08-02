#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


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
      int sz = g[n].size();
      vector<pair<ll,ll>> _dp(sz+1, {0,0});
      rep(i,sz) {
        _dp[i+1] = {_dp[i].first + _dp[i].second*g[n][i].dp, _dp[i].second+g[n][i].dp};
      }
      rep(i,sz)
        dp[n] += _dp[i].first*g[n][i].dp;
      // dp[n] = buff;
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

    vector<sum_t> solve() {
      dfs_sub(0,-1);
      dfs_all(0,-1,ident);
      return dp;
    }
};

int main() {
  int N;
  cin >> N;
  auto f = [](ll a, ll b){return a+b;};
  ReRooting<ll, ll> tree(N, f, f, 0);
  rep(_,N-1) {
    int A,B;
    cin >> A >> B;
    A--; B--;
    tree.add_edge(A,B,1);
  }
  vector<ll> dp = tree.solve();
  ll res = 0;
  for (ll a: dp)
    res += a;
  print(res);
  return 0;
}
