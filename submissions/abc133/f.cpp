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
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << endl


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

struct Edge {
  int to; int c; int l;
};
struct Query {
  int id; int color; int len; int mult;
};
vector<vector<Edge>> E(100005);
vector<vector<Query>> que(100005);
vector<ll> csum(100005);
vector<int> cnt(100005);
vector<ll> res;


void dfs(int u, int p, ll sum) {
  for (auto q: que[u]) {
    int id = q.id, c = q.color, l = q.len, m = q.mult;
    res[id] += (sum - csum[c] + cnt[c] * l) * m;
  }
  for (auto e: E[u]) {
    if (e.to == p)
      continue;
    csum[e.c] += e.l;
    cnt[e.c]++;
    dfs(e.to, u, sum+e.l);
    csum[e.c] -= e.l;
    cnt[e.c]--;
  }
  return ;
}

int main() {
  int N,Q;
  cin >> N >> Q;
  res.resize(Q);
  HLDecomposition hld(N);
  rep(_,N-1) {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    a--; b--; c--;
    E[a].push_back(Edge{b,c,d});
    E[b].push_back(Edge{a,c,d});
    hld.add_edge(a,b);
  }
  hld.build();
  rep(i,Q) {
    int x,y,u,v;
    cin >> x >> y >> u >> v;
    x--; u--; v--;
    que[u].push_back(Query{i,x,y,1});
    que[v].push_back(Query{i,x,y,1});
    que[hld.lca(u,v)].push_back(Query{i,x,y,-2});
  }
  dfs(0,-1,0);
  printall(res);
  return 0;
}