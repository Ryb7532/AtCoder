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


class PreorderTree {
  int id = 0;

public:
  int N;
  vector<vector<int>> E;
  vector<int> L, R, P, _old_node_id;
  // L[n]: new node id of n, R[n]: new node id of rightmost descendant

  PreorderTree(int n, const vector<pair<int,int>> &e, int s=0)
      : N(n), E(N), L(N,-1), R(N,-1), P(N,-1), _old_node_id(N,-1) {
    assert(e.size() == N-1);
    rep(i,N-1) {
      E[e[i].first].push_back(i);
      E[e[i].second].push_back(i);
    }

    vector<int> stack;
    vector<int> seen(N, 0);
    L[s] = id;
    _old_node_id[id] = s;
    id++;
    stack.push_back(s);
    while (stack.size() > 0) {
      int u = stack.back();
      if (seen[u] >= E[u].size()) {
        R[u] = id;
        stack.pop_back();
        continue;
      }
      int eid = E[u][seen[u]];
      int v = (e[eid].first == u) ? e[eid].second : e[eid].first;
      if (L[v] == -1) {
        L[v] = id;
        _old_node_id[id] = v;
        id++;
        stack.push_back(v);
        P[v] = u;
      }
      seen[u]++;
    }
  }

  int edge(int old_id, int id) {
    assert(0 <= id && id < E[old_id].size());
    return E[old_id][id];
  }

  int new_node_id(int old_id) {
    assert(0 <= old_id && old_id < N);
    return L[old_id];
  }

  int old_node_id(int new_id) {
    assert(0 <= new_id && new_id < N);
    return _old_node_id[new_id];
  }

  int parent(int old_id) {
    assert(0 <= old_id && old_id < N);
    return P[old_id];
  }
};


// Task: Range Update Query
// Segment Tree with Lazy Propagation
template < typename Monoid, typename OperatorMonoid = Monoid >
class RUQ {
  using F = function<Monoid(Monoid, Monoid, int, int)>;
  using G = function<Monoid(Monoid, OperatorMonoid, int)>;
  using H = function<OperatorMonoid(OperatorMonoid,OperatorMonoid)>;
  int n, sz, height;
  vector<Monoid> data;
  vector<OperatorMonoid> lazy;
  vector<int> length;
  // Binary-op in Monoid
  const F f;
  // Function that calculate new value of data
  const G g;
  // Binary-op in OperatorMonoid
  const H h;
  // identity element of Monoid
  const Monoid mi;
  // identity element of OperatorMonoid
  const OperatorMonoid omi;

  // update the value of k-th node (one up)
  inline void update(int k) {
    data[k] = f(data[2*k+0], data[2*k+1], length[2*k+0], length[2*k+1]);
  }
  // apply given OperatorMonoid to k-th node
  inline void apply(int k, const OperatorMonoid &x) {
    data[k] = g(data[k], x, length[k]);
    if (k<sz) lazy[k] = h(lazy[k], x);
  }
  // propagate lazy of k-th node to its children
  inline void propagate(int k) {
    if (lazy[k] != omi) {
      apply(2*k+0, lazy[k]);
      apply(2*k+1, lazy[k]);
      lazy[k] = omi;
    }
  }
  // update the ancestors of k-th node from top to bottom
  inline void thrust(int k, bool r) {
    for (int i=height; i>0; i--) {
      if (((k>>i)<<i) != k) propagate((k-r)>>i);
    }
  }
  // update the ancestors of k-th node from bottom to top
  inline void updates(int k, bool r) {
    for (int i=1; i<=height; i++) {
      if (((k>>i)<<i) != k) update((k-r)>>i);
    }
  }

public:
  RUQ(int n, const F f, const G g, const H h, const Monoid &mi, const OperatorMonoid omi)
      : n(n), f(f), g(g), h(h), mi(mi), omi(omi) {
    sz = 1;
    height = 0;
    while(sz<n) sz <<= 1, height++;
    data.assign(2*sz, mi);
    lazy.assign(2*sz, omi);
    length.assign(2*sz, 1);
  }
  // let k-th element as x
  void set(int k, const Monoid &x) {
    data[k+sz] = x;
  }
  // build the segment tree
  void build() {
    for(int k=sz-1; k>0; k--) {
      update(k);
      length[k] = length[2*k] + length[2*k+1];
    }
  }
  // update the elements in range [a,b) by x
  void update(int a, int b, const OperatorMonoid &x) {
    if (b > n) b = n;
    if (a >= b) return ;
    thrust(a += sz, false);
    thrust(b += sz, true);
    for (int l = a, r = b; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(l++, x);
      if (r & 1) apply(--r, x);
    }
    updates(a, false);
    updates(b, true);
  }
  // calculete f in [a,b)
  Monoid query(int a, int b) {
    if (b > n) b = n;
    if (a >= b) return mi;
    thrust(a += sz, false);
    thrust(b += sz, true);
    Monoid L = mi, R = mi;
    int ll = 0, lr = 0;
    for(int l = a, r = b; l < r; l >>= 1, r >>= 1) {
      if(l & 1) L = f(L, data[l], ll, length[l]), ll += length[l], l++;
      if(r & 1) --r, R = f(data[r], R, length[r], lr), lr += length[r];
    }
    return f(L, R, ll, lr);
  }
  // get k-th element (0<=k<sz)
  Monoid operator[](const int &k) {
    return query(k, k+1);
  }
  // return minimum x such that satisfy "check" in [a,x)
  template< typename C >
  int find_first(int a, const C &check) {
    if (a >= n) return n;
    thrust(a += sz, false);
    Monoid L = mi;
    int ll = 0;
    do {
      while ((a&1) == 0) a >>= 1;
      Monoid nxt = f(L, data[a], ll, length[a]);
      if(check(nxt)) {
        while (a < sz) {
          propagate(a);
          a <<= 1;
          nxt = f(L, data[a], ll, length[a]);
          if (!check(nxt)) {
            L = nxt;
            ll += length[a];
            a++;
          }
        }
        return a + 1 - sz;
      }
      L = nxt;
      ll += length[a];
      a++;
    } while ((a & -a) != a);
    return n;
  }
  // return maximum x such that satisfy "check" in [x,b)
  template< typename C >
  int find_last(int b, const C &check) {
    if (b <= 0) return -1;
    thrust(b += sz, true);
    Monoid R = mi;
    int lr = 0;
    b++;
    do {
      b--;
      while (b > 1 && (b&1)) b >>= 1;
      Monoid nxt = f(data[b], R, length[b], lr);
      if(check(nxt)) {
        while (b < sz) {
          propagate(b);
          b = (b << 1) + 1;
          nxt = f(data[b], R, length[b], lr);
          if (!check(nxt)) {
            R = nxt;
            lr += length[b];
            b--;
          }
        }
        return b - sz;
      }
      R = nxt;
      lr += length[b];
    } while ((b & -b) != b);
    return -1;
  }
};


int main() {
  int N;
  scan(N);
  vector<pair<int,int>> e(N-1);
  vector<ll> l(N-1);
  rep(i,N-1) {
    int u,v;
    scan(u, v, l[i]);
    u--;
    v--;
    e[i] = {u,v};
  }
  PreorderTree pot(N, e, 0);
  vector<int> stack;
  vector<int> seen(N,0);
  vector<ll> D(N,-1);
  stack.push_back(0);
  D[0] = 0;
  while (stack.size() > 0) {
    int u = stack.back();
    int id = seen[u];
    if (id >= pot.E[u].size()) {
      stack.pop_back();
      continue;
    }
    int eid = pot.edge(u, seen[u]);
    int v = (e[eid].first == u) ? e[eid].second : e[eid].first;
    if (v != pot.parent(u)) {
      D[v] = D[u] + l[eid];
      stack.push_back(v);
    }
    seen[u]++;
  }

  using Monoid = pair<ll, int>;
  using OperatorMonoid = ll;
  auto f = [](Monoid a, Monoid b, int l, int r) {
    if (a.first < b.first)
      return b;
    return a;
  };
  auto g = [](Monoid a, OperatorMonoid b, int l) {
    return Monoid(a.first - b, a.second);
  };
  auto h = [](OperatorMonoid a, OperatorMonoid b) {
    return a + b;
  };
  RUQ<Monoid, OperatorMonoid> seg(N, f, g, h, Monoid(0,0), 0);
  rep(i,N) {
    seg.set(pot.new_node_id(i), Monoid(D[i], i));
  }
  seg.build();
  vector<bool> visited(N, false);
  visited[0] = true;

  ll res = 0;
  rep(i,N) {
    vector<int> seen;
    auto [d, id] = seg.query(0, N);
    res += 2*d;
    while (id != -1 && !visited[id]) {
      seen.push_back(id);
      id = pot.parent(id);
    }
    while (seen.size() > 0) {
      id = seen.back();
      seen.pop_back();
      auto [d, _] = seg[pot.new_node_id(id)];
      seg.update(pot.new_node_id(id), pot.R[id], d);
      visited[id] = true;
    }
    print(res);
  }
  return 0;
}