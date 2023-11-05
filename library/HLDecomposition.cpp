#include <bits/stdc++.h>
using namespace std;


class HLDecomposition {
  int V;
  vector<vector<int>> E;
  vector<int> size, par, pathtop, in, out;
  int root;

  void build_size(int u, int p) {
    size[u] = 1;
    par[u] = p;
    for (int &v: E[u]) {
      if (v == p) {
        if (v == E[u].back()) break;
        else swap(v, E[u].back());
      }
      build_size(v, u);
      size[u] += size[v];
      if (size[v] > size[E[u][0]])
        swap(v, E[u][0]);
    }
  }

  void build_path(int u, int p, int &ord) {
    in[u] = ord++;
    for (int v: E[u]) {
      if (v == p) continue;
      pathtop[v] = (v == E[u][0] ? pathtop[u] : v);
      build_path(v, u, ord);
    }
    out[u] = ord;
  }

public:
  HLDecomposition(int n) : V(n), E(V), size(V), par(V,-1), pathtop(V,-1), in(V,-1), out(V,-1) {}

  void add_edge(int u, int v) {
    E[u].push_back(v);
    E[v].push_back(u);
  }

  void build(int r=0) {
    root = r;
    int ord = 0;
    build_size(root, -1);
    pathtop[root] = root;
    build_path(root, -1, ord);
  }

  inline int get(int a) {
    return in[a];
  }

  int lca(int a, int b) {
    int pa = pathtop[a], pb = pathtop[b];
    while (pathtop[a] != pathtop[b]) {
      if (in[pa] > in[pb]) {
        a = par[pa];
        pa = pathtop[a];
      } else {
        b = par[pb];
        pb = pathtop[b];
      }
    }
    if (in[a] > in[b]) swap(a,b);
    return a;
  }

  void subtree_query(int a, const function<void(int,int)> &func) {
    func(in[a], out[a]+1);
  }

  void path_query(int a, int b, const function<void(int,int)> &func) {
    int pa = par[a], pb = par[b];
    while (pathtop[a] != pathtop[b]) {
      if (in[pa] > in[pb]) {
        func(in[pa], in[a]+1);
        a = par[pa], pa = pathtop[a];
      } else {
        func(in[pb], in[b]+1);
        b = par[pb], pb = pathtop[b];
      }
    }
    if (in[a] > in[b]) swap(a,b);
    func(in[a], in[b]+1);
  }
};
