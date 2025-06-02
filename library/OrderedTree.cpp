#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()


class OrderedTree {
  int id = 0;
  int N;
  vector<vector<pair<int,int>>> E;
  vector<int> ranks, order, par;

  void calc_order() {
    rep(i,N) {
      int r = ranks[i];
      assert(0 <= r && r < N);
      assert(order[r] == -1);
      order[r] = i;
    }
  }

public:
  vector<int> left, right;

  OrderedTree(int n, const vector<pair<int,int>> &e, const int s=0, const string &ord="pre")
      : N(n), E(N), ranks(N,-1), order(N,-1), par(N,-1), left(N), right(N) {
    assert(e.size() == N-1);
    assert(0 <= s && s < N);
    assert(ord == "pre" || ord == "post");
    rep(i,N-1) {
      int u = e[i].first, v = e[i].second;
      assert(0 <= u && u < N);
      assert(0 <= v && v < N);
      E[u].push_back({i, v});
      E[v].push_back({i, u});
    }
    vector<int> dfs_stack;
    vector<int> seen(N, 0);
    dfs_stack.push_back(s);
    while ((int)dfs_stack.size() > 0) {
      int u = dfs_stack.back();
      if (seen[u] == 0) {
        left[u] = id;
        if (ord == "pre") ranks[u] = id++;
      }
      if (seen[u] >= (int)E[u].size()) {
        if (ord == "post") ranks[u] = id++;
        right[u] = id;
        dfs_stack.pop_back();
        continue;
      }
      int v = E[u][seen[u]].second;
      if (par[u] != v) {
        par[v] = u;
        dfs_stack.push_back(v);
      }
      seen[u]++;
    }
    assert(id == N);
    calc_order();
  }

  int operator[](const int &idx) const {
    assert(0 <= idx && idx < N);
    return order[idx];
  }

  int get_rank(int node_id) const {
    assert(0 <= node_id && node_id < N);
    return ranks[node_id];
  }

  pair<int,int> get_edge(int node_id, int id) const {
    assert(0 <= node_id && node_id < N);
    assert(0 <= id && id < (int)E[node_id].size());
    return E[node_id][id];
  }

  int parent(int node_id) const {
    assert(0 <= node_id && node_id < N);
    return par[node_id];
  }

  bool is_root(int node_id) const {
    assert(0 <= node_id && node_id < N);
    return par[node_id] == -1;
  }
};
