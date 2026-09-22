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

template<typename data_t, typename sum_t>
class ReRooting {
private:
  struct Edge { int to; data_t data; sum_t dp, ndp; };
  // Function to merge data
  using F = function<sum_t(sum_t,sum_t)>;
  // Function to calculate the value of the subtree
  using G = function<sum_t(sum_t,data_t)>;

  const sum_t ident;
  vector<vector<Edge>> g;
  vector<sum_t> subdp, dp;
  const F f1;
  const G f2;

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
    ident(ident), g(n), subdp(n, ident), dp(n, ident), f1(f1), f2(f2) {}

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


int main() {
  int N;
  scan(N);
  vector<vector<int>> g(N);
  vector<int> degree(N, 0);
  ReRooting<int, pair<ll, int>> reroot(N,
    [&](pair<ll, int> a, pair<ll, int> b) {
      return make_pair(a.first + b.first, a.second + 1);
    },
    [&](pair<ll, int> a, int b) {
      if (degree[b] == 2) {
        return make_pair((ll)1, a.second);
      } else if (degree[b] == 3) {
        return make_pair(a.first, a.second);
      }
      return make_pair((ll)0, a.second);
    },
    make_pair((ll)0, 0));
  rep(i,N-1) {
    int u, v;
    scan(u, v);
    u--; v--;
    degree[u]++;
    degree[v]++;
    g[u].push_back(v);
    g[v].push_back(u);
    reroot.add_edge_bi(u, v, v, u);
  }
  reroot.solve();
  ll res = 0;
  rep(i,N) {
    auto [a, b] = reroot[i];
    if (b == 2) {
      res += a;
    }
  }
  rep(i,N) {
    fore(e, g[i]) {
      if (degree[i] == 2 && degree[e] == 2) {
        res--;
      }
    }
  }
  print(res / 2);
  return 0;
}