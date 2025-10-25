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
  // return minimum x such that satisfy "check" in [a,x]
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
        return a - sz;
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
  int N,Q;
  scan(N);
  vector<ll> X(N);
  rep(i,N) {
    scan(X[i]);
    X[i] -= i;
  }

  using Monoid = tuple<ll, ll, ll>;
  using OperatorMonoid = ll;
  const ll INF = 1e18;
  auto f = [](Monoid a, Monoid b, int l, int r) {
    auto [sa, Ma, ma] = a;
    auto [sb, Mb, mb] = b;
    return Monoid(sa+sb, max(Ma, Mb), min(ma, mb));
  };
  auto g = [](Monoid a, OperatorMonoid b, int l) {
    return Monoid(b*l, b, b);
  };
  auto h = [](OperatorMonoid a, OperatorMonoid b) {
    return b;
  };
  RUQ<Monoid, OperatorMonoid> seg(N, f, g, h, Monoid(0, -INF, INF), INF);
  rep(i,N) {
    seg.set(i, Monoid(X[i], X[i], X[i]));
  }
  seg.build();

  ll res = 0;
  scan(Q);
  rep(_,Q) {
    int T;
    ll G;
    scan(T,G);
    T--;
    G -= T;
    auto [x, _M, _m] = seg[T];
    int l, r;
    if (x < G) {
      auto check = [&G](Monoid a) {
        auto [_0, M, _1] = a;
        return M >= G;
      };
      l = T;
      r = seg.find_first(0, check);
      auto [cost, _0, _1] = seg.query(l, r);
      res += G * (r-l) - cost;
    } else {
      auto check = [&G](Monoid a) {
        auto [_0, _1, m] = a;
        return  m < G;
      };
      l = seg.find_last(T, check) + 1;
      r = T + 1;
      auto [cost, _0, _1] = seg.query(l, r);
      res += cost - G * (r-l);
    }
    seg.update(l, r, G);
  }
  print(res);
  return 0;
}