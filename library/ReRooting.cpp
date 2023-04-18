#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename Data, typename T>
class ReRooting {
  private:
    struct Node { int to, rev; Data data; };
    // Function to merge data
    using F1 = function<T(T,T)>;
    // Function to calculate the value of the subtree
    using F2 = function<T(T,Data)>;
    int n;
    vector<vector<Node>> g;
    vector<vector<T>> ldp, rdp;
    vector<int> lptr, rptr;
    const F1 f1;
    const F2 f2;
    const T ident;

    T dfs(int id, int p) {
      while (lptr[id] != p && lptr[id] < g[id].size()) {
        int lp = lptr[id];
        auto &e = g[id][lp];
        ldp[id][lp + 1] = f1(ldp[id][lp], f2(dfs(e.to, e.rev), e.data));
        lptr[id]++;
      }
      while (rptr[id] != p && rptr[id] >= 0) {
        int rp = rptr[id];
        auto &e = g[id][rp];
        rdp[id][rp] = f1(rdp[id][rp + 1], f2(dfs(e.to, e.rev), e.data));
        rptr[id]--;
      }
      if (p < 0) return rdp[id][0];
      return f1(ldp[id][p], rdp[id][p + 1]);
    }

  public:
    ReRooting(int n, const F1 &f1, const F2 &f2, const &ident) :
      n(n), g(n), ldp(n), rdp(n), lptr(n), rptr(n), f1(f1), f2(f2), ident(ident) {}

    void add_edge(int u, int v, const Data &d) {
      g[u].emplace_back({v, (int)g[v].size(), d});
      g[v].emplace_back({u, (int)g[u].size()-1, d});
    }

    void add_edge_bi(int u, int v, const Data &d, const Data &e) {
      g[u].emplace_back({v, (int)g[v].size(), d});
      g[v].emplace_back({u, (int)g[u].size()-1, e});
    }

    vector<T> solve() {
      rep(i,g.size()) {
        int sz = g[i].size();
        ldp[i].assign(sz + 1, ident);
        rdp[i].assign(sz + 1, ident);
        lptr[i] = 0;
        rptr[i] = sz - 1;
      }
      vector<T> res;
      rep(i,n) {
        res.push_back(dfs(i, -1));
      }
      return res;
    }
};
