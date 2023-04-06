#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int N;
const int M = 2e5;
const int INF = 1e9;
vector<vector<pair<int,int>>> Edge(M);
vector<ll> C(M);


// Task: Subset Sum Problem
// Binary Indexed Tree (Point Update and Range Query)
template<typename T>
struct BIT {
  int n;
  vector<T> dat;
  BIT(int n) : n(n), dat(n+1,0){}
  void add(int i,T x) {
    for (++i; i<=n; i+=(i&-i)) dat[i] += x;
  }
  T sum(int i) {
    T res = 0;
    for (++i; i>0; i-=(i&-i))
      res += dat[i];
    return res;
  }
  T range_sum(int l,int r) { // [l,r)
    return sum(r-1)-sum(l-1);
  }
}; // 0-indexed


// Task: Range Maximum(Minimum) Query
// Segment Tree
template < typename Monoid >
class RMQ {
  // Binary-op in Monoid
  using F = function<Monoid(Monoid, Monoid)>;
  int sz;
  vector<Monoid> data;
  const F f;
  // identity element of Monoid
  const Monoid M1;

  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while(a<sz) {
      Monoid nxt = type ? f(data[2*a+type], M) : f(M, data[2*a+type]);
      if(check(nxt)) a = 2*a+type;
      else M = nxt, a = 2*a+1-type;
    }
    return a - sz;
  }

  public:
    RMQ(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
      sz = 1;
      while(sz<n) sz <<= 1;
      data.assign(2*sz, M1);
    }
    // let k-th element as x
    void set(int k, const Monoid &x) {
      data[k+sz] = x;
    }
    // build the segment tree
    void build() {
      for(int k=sz-1; k>0; k--) {
        data[k] = f(data[2*k], data[2*k+1]);
      }
    }
    // update k-th element to x
    void update(int k, const Monoid &x) {
      k += sz;
      data[k] = x;
      while(k>>=1) {
        data[k] = f(data[2*k], data[2*k+1]);
      }
    }
    // calculete f in [a,b)
    Monoid query(int a, int b) {
      Monoid L = M1, R = M1;
      for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
        if(a & 1) L = f(L, data[a++]);
        if(b & 1) R = f(data[--b], R);
      }
      return f(L, R);
    }
    // get value of k-th (0<=k<sz)
    Monoid operator[](const int &k) const {
      return data[k+sz];
    }
    // return minimum x such that satisfy check in [a,x)
    template< typename C >
    int find_first(int a, const C &check) {
      Monoid L = M1;
      if(a <= 0) {
        if(check(f(L, data[1]))) return find_subtree(1, check, L, false);
        return -1;
      }
      int b = sz;
      for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
        if(a & 1) {
          Monoid nxt = f(L, data[a]);
          if(check(nxt)) return find_subtree(a, check, L, false);
          L = nxt;
          ++a;
        }
      }
      return -1;
    }
    // return maximum x such that satisfy check in [x,b)
    template< typename C >
    int find_last(int b, const C &check) {
      Monoid R = M1;
      if(b >= sz) {
        if(check(f(data[1], R))) return find_subtree(1, check, R, true);
        return -1;
      }
      int a = sz;
      for(b += sz; a < b; a >>= 1, b >>= 1) {
        if(b & 1) {
          Monoid nxt = f(data[--b], R);
          if(check(nxt)) return find_subtree(b, check, R, true);
          R = nxt;
        }
      }
      return -1;
    }
};


BIT<ll> dist(2*M);
RMQ<pair<int,int>> lca(2*M, [](pair<int,int> a, pair<int,int> b){ return min(a,b); }, {INF,INF});
vector<int> first_visit(M);
vector<pair<int,int>> passedge(M);
int id;

void dfs(int n, int p, int d, ll c) {
  dist.add(id, c);
  lca.set(id, {d, n});
  first_visit[n] = id;
  id++;
  for (auto e: Edge[n]) {
    if (e.first == p)
      continue;
    passedge[e.second].first = id;
    dfs(e.first, n, d+1, C[e.second]);
    dist.add(id, -C[e.second]);
    lca.set(id, {d, n});
    passedge[e.second].second = id;
    id++;
  }
}

int main() {
  cin >> N;
  rep(i,N-1) {
    int u,v;
    cin >> u >> v >> C[i];
    u--; v--;
    Edge[u].push_back({v,i});
    Edge[v].push_back({u,i});
  }
  dfs(0,0,0,0);
  lca.build();
  int Q;
  cin >> Q;
  rep(_,Q) {
    int t,a,b;
    cin >> t >> a >> b;
    if (t == 1) {
      a--;
      dist.add(passedge[a].first, b-C[a]);
      dist.add(passedge[a].second, C[a]-b);
      C[a] = b;
    } else {
      a--; b--;
      ll res = 0;
      int va = first_visit[a], vb = first_visit[b];
      if (va > vb)
        swap(va,vb);
      res += dist.sum(va);
      res += dist.sum(vb);
      int c = lca.query(va, vb+1).second;
      res -= 2 * dist.sum(first_visit[c]);
      print(res);
    }
  }
  return 0;
}
