#include <bits/stdc++.h>
using namespace std;


template < typename Monoid >
struct RMQ {
  //Binary-op that merges the elements of two sub-arrays
  using F = function<Monoid(Monoid, Monoid)>;
  int sz;
  vector<Monoid> data;
  const F f;
  const Monoid M1; // identity element of monoid
  RMQ(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz<n) sz <<= 1;
    data.assign(2*sz, M1);
  }
  void set(int k, const Monoid &x) {
    data[k+sz] = x;
  }
  void build() {
    for(int k=sz-1; k>0; k--) {
      data[k] = f(data[2*k], data[2*k+1]);
    }
  }
  void update(int k, const Monoid &x) {
    k += sz;
    data[k] = x;
    while(k>>=1) {
      data[k] = f(data[2*k], data[2*k+1]);
    }
  }
  //[a,b)
  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, data[a++]);
      if(b & 1) R = f(data[--b], R);
    }
    return f(L, R);
  }
  //0<=k<sz
  Monoid operator[](const int &k) const {
    return data[k+sz];
  }
  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while(a<sz) {
      Monoid nxt = type ? f(data[2*a+type], M) : f(M, data[2*a+type]);
      if(check(nxt)) a = 2*a+type;
      else M = nxt, a = 2*a+1-type;
    }
    return a - sz;
  }
  //return a first element-num of x that satisfy check in [a,x)
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
  //return a last element-num of x that satisfy check in [x,b)
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


template < typename Monoid, typename OperatorMonoid = Monoid >
struct RUQ {
  // Binary-op that merges data's two sub-arrays
  using F = function<Monoid(Monoid, Monoid)>;
  // Binary-op that merges data and lazy
  using G = function<Monoid(Monoid, OperatorMonoid)>;
  // Binary-op that merges lazy's two sub-arrays
  using H = function<OperatorMonoid(OperatorMonoid,OperatorMonoid)>;
  int sz, height;
  vector<Monoid> data;
  vector<OperatorMonoid> lazy;
  const F f;
  const G g;
  const H h;
  const Monoid M1; // identity element of monoid
  const OperatorMonoid OM0;
  RUQ(int n, const F f, const G g, const H h, const Monoid &M1, const OperatorMonoid OM0)
      : f(f), g(g), h(h), M1(M1), OM0(OM0) {
    sz = 1;
    height = 0;
    while(sz<n) sz <<= 1, height++;
    data.assign(2*sz, M1);
    lazy.assign(2*sz, OM0);
  }
  void set(int k, const Monoid &x) {
    data[k+sz] = x;
  }
  void build() {
    for(int k=sz-1; k>0; k--) {
      data[k] = f(data[2*k], data[2*k+1]);
    }
  }
  inline void propagate(int k) {
    if (lazy[k] != OM0) {
      lazy[2*k] = h(lazy[2*k], lazy[k]);
      lazy[2*k+1] = h(lazy[2*k+1], lazy[k]);
      data[k] = reflect(k);
      lazy[k] = OM0;
    }
  }
  inline Monoid reflect(int k) {
    return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);
  }
  inline void recalc(int k) {
    while(k >>= 1) data[k] = f(reflect(2*k), reflect(2*k+1));
  }
  inline void thrust(int k) {
    for (int i=height; i>0; i--) propagate(k>>i);
  }
  // [a,b)
  void update(int a, int b, const OperatorMonoid &x) {
    thrust(a += sz);
    thrust(b += sz-1);
    for (int l = a, r = b+1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) lazy[l] = h(lazy[l], x), ++l;
      if (r & 1) --r, lazy[r] = h(lazy[r], x);
    }
    recalc(a);
    recalc(b);
  }
  // [a,b)
  Monoid query(int a, int b) {
    thrust(a += sz);
    thrust(b += sz-1);
    Monoid L = M1, R = M1;
    for(int l = a, r = b+1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) L = f(L, reflect(l++));
      if(r & 1) R = f(reflect(--r), R);
    }
    return f(L, R);
  }
  // 0<=k<sz
  Monoid operator[](const int &k) {
    return query(k, k+1);
  }
  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while(a<sz) {
      propagate(a);
      Monoid nxt = type ? f(reflect(2*a+type), M) : f(M, reflect(2*a+type));
      if(check(nxt)) a = 2*a+type;
      else M = nxt, a = 2*a+1-type;
    }
    return a - sz;
  }
  // return a first element-num of x that satisfy check in [a,x)
  template< typename C >
  int find_first(int a, const C &check) {
    Monoid L = M1;
    if(a <= 0) {
      if(check(f(L, reflect(1)))) return find_subtree(1, check, L, false);
      return -1;
    }
    thrust(a + sz);
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        Monoid nxt = f(L, reflect(a));
        if(check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }
  // return a last element-num of x that satisfy check in [x,b)
  template< typename C >
  int find_last(int b, const C &check) {
    Monoid R = M1;
    if(b >= sz) {
      if(check(f(reflect(1), R))) return find_subtree(1, check, R, true);
      return -1;
    }
    thrust(b + sz - 1);
    int a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        Monoid nxt = f(reflect(--b), R);
        if(check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};
