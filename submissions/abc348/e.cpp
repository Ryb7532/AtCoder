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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define out1(a) cout << (a) << endl
#define out2(a,b) cout << (a) << " " << (b) << endl
#define out3(a,b,c) cout << (a) << " " << (b) << " " << (c) << endl
#define print(...) GET_MACRO(__VA_ARGS__,out3,out2,out1)(__VA_ARGS__)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyn(f) cout << (f ? Yes : No) << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}

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

int main() {
  int N;
  cin >> N;
  vector<int> A(N-1), B(N-1);
  vector<ll> C(N);
  rep(i,N-1) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
  }
  rep(i,N) {
    cin >> C[i];
  }
  using data_t = ll;
  using sum_t = pair<data_t,data_t>;
  auto f1 = [](sum_t a, sum_t b) {
    return (sum_t){a.first+b.first, a.second+b.second};
  };
  auto f2 = [](sum_t a, data_t b) {
    return (sum_t){a.first+a.second+b, a.second+b};
  };
  ReRooting<data_t, sum_t> tree(N, f1, f2, (sum_t){0,0});
  rep(i,N-1) {
    tree.add_edge_bi(A[i], B[i], C[B[i]], C[A[i]]);
  }
  tree.solve();
  data_t res = 8e18;
  rep(i,N) {
    chmin(res, tree[i].first);
  }
  print(res);
  return 0;
}