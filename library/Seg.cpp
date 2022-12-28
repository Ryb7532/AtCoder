#include <bits/stdc++.h>
using namespace std;

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


// Task: Range Update Query
// Segment Tree with Lazy Propagation
template < typename Monoid, typename OperatorMonoid = Monoid >
class RUQ {
  using F = function<Monoid(Monoid, Monoid)>;
  using G = function<Monoid(Monoid, OperatorMonoid, int)>;
  using H = function<OperatorMonoid(OperatorMonoid,OperatorMonoid)>;
  int sz, height;
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
  const Monoid M1;
  // identity element of OperatorMonoid
  const OperatorMonoid OM0;

  // calculate new value of k-th node
  inline Monoid reflect(int k) {
    return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k], length[k]);
  }
  // propagate lazy of k-th node to its children and update k-th node
  inline void propagate(int k) {
    if (lazy[k] != OM0) {
      lazy[2*k] = h(lazy[2*k], lazy[k]);
      lazy[2*k+1] = h(lazy[2*k+1], lazy[k]);
      data[k] = reflect(k);
      lazy[k] = OM0;
    }
  }
  // update the ancestors of k-th node
  inline void recalc(int k) {
    while(k >>= 1) data[k] = f(reflect(2*k), reflect(2*k+1));
  }
  // update the ancestors of k-th node in order from the root node
  inline void thrust(int k) {
    for (int i=height; i>0; i--) propagate(k>>i);
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

  public:
    RUQ(int n, const F f, const G g, const H h, const Monoid &M1, const OperatorMonoid OM0)
        : f(f), g(g), h(h), M1(M1), OM0(OM0) {
      sz = 1;
      height = 0;
      while(sz<n) sz <<= 1, height++;
      data.assign(2*sz, M1);
      lazy.assign(2*sz, OM0);
      length.assign(2*sz, 1);
    }
    // let k-th element as x
    void set(int k, const Monoid &x) {
      data[k+sz] = x;
    }
    // build the segment tree
    void build() {
      for(int k=sz-1; k>0; k--) {
        data[k] = f(data[2*k], data[2*k+1]);
        length[k] = length[2*k] + length[2*k+1];
      }
    }
    // update the elements in range [a,b) by x
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
    // calculete f in [a,b)
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
    // get k-th element (0<=k<sz)
    Monoid operator[](const int &k) {
      return query(k, k+1);
    }
    // return minimum x such that satisfy "check" in [a,x)
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
    // return maximum x such that satisfy "check" in [x,b)
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


// Two-dimentional (height x width) Segment Tree
// single point update, rectangular query
template< typename structure_t, typename get_t, typename update_t = get_t >
class Seg2D {
  using F = function<get_t(get_t, get_t)>;
  using G = function<get_t(structure_t &, int, int)>;
  using H = function<void(structure_t &, int, update_t)>;
  int sz;
  vector<structure_t> seg;
  // Binary-op in Monoid (get_t)
  const F f;
  // Function that calculate f in range [x,y) of structure_t (such BIT, RMP)
  const G g;
  // Function that update x-th element of structure_t by z
  const H h;
  // identity element of Monoid
  const get_t identity;
  // beet[k]: index set of columns with values in rows covered by k-th node
  vector<vector<int>> beet;
  // LL[k][x] (,RR[k][x]): minimum index of left (right) child's beet that is not lower than beet[k][x]
  vector<vector<int>> LL, RR;

  // update the element in (a, beet[k][x] ) by z ([l,r) is the range of rows covered by k-th node)
  void update(int a, int x, update_t z, int k, int l, int r) {
    if(r <= a || a + 1 <= l) return;
    if(a <= l && r <= a + 1) return h(seg[k], x, z);
    update(a, LL[k][x], z, 2 * k + 0, l, (l + r) >> 1);
    update(a, RR[k][x], z, 2 * k + 1, (l + r) >> 1, r);
    return h(seg[k], x, z);
  }
  // calculate f in [a,b)x[ beet[k][x], beet[k][y] ) ([l,r) is the range of rows covered by k-th node)
  get_t query(int a, int b, int x, int y, int k, int l, int r) {
    if(a >= r || b <= l) return identity;
    if(a <= l && r <= b) return g(seg[k], x, y);
    return f(query(a, b, LL[k][x], LL[k][y], 2 * k + 0, l, (l + r) >> 1),
             query(a, b, RR[k][x], RR[k][y], 2 * k + 1, (l + r) >> 1, r));
  }

  public:
    // let n is height
    Seg2D(int n, const F &f, const G &g, const H &h, const get_t &identity)
        : f(f), g(g), h(h), identity(identity) {
      sz = 1;
      while(sz < n) sz <<= 1;
      beet.resize(2 * sz);
      LL.resize(2 * sz);
      RR.resize(2 * sz);
    }
    // predefine x,y that is updated
    void preupdate(int x, int y) {
      beet[x + sz].push_back(y);
    }
    // build the two-dimentional segment tree
    void build() {
      // sort and remove duplicate elements
      for(int k = (int) beet.size() - 1; k >= sz; k--) {
        sort(begin(beet[k]), end(beet[k]));
        beet[k].erase(unique(begin(beet[k]), end(beet[k])), end(beet[k]));
      }
      for(int k = sz - 1; k > 0; k--) {
        // merge its children's arrays and remove duplicate elements (sorted)
        beet[k].resize(beet[2 * k + 0].size() + beet[2 * k + 1].size());
        merge(begin(beet[2 * k + 0]), end(beet[2 * k + 0]), begin(beet[2 * k + 1]), end(beet[2 * k + 1]), begin(beet[k]));
        beet[k].erase(unique(begin(beet[k]), end(beet[k])), end(beet[k]));
        // calculate LL and RR
        LL[k].resize(beet[k].size() + 1);
        RR[k].resize(beet[k].size() + 1);
        int tail1 = 0, tail2 = 0;
        for(int i = 0; i < beet[k].size(); i++) {
          while(tail1 < beet[2 * k + 0].size() && beet[2 * k + 0][tail1] < beet[k][i]) ++tail1;
          while(tail2 < beet[2 * k + 1].size() && beet[2 * k + 1][tail2] < beet[k][i]) ++tail2;
          LL[k][i] = tail1, RR[k][i] = tail2;
        }
        LL[k][beet[k].size()] = (int) beet[2 * k + 0].size();
        RR[k][beet[k].size()] = (int) beet[2 * k + 1].size();
      }
      for(int k = 0; k < beet.size(); k++) {
        seg.emplace_back(structure_t(beet[k].size()));
      }
    }
    // update the element in x,y by z
    void update(int x, int y, update_t z) {
      y = lower_bound(begin(beet[1]), end(beet[1]), y) - begin(beet[1]);
      return update(x, y, z, 1, 0, sz);
    }
    // calculete f in [a,b)x[x,y)
    get_t query(int a, int b, int x, int y) {
      x = lower_bound(begin(beet[1]), end(beet[1]), x) - begin(beet[1]);
      y = lower_bound(begin(beet[1]), end(beet[1]), y) - begin(beet[1]);
      return query(a, b, x, y, 1, 0, sz);
    }
};

// examples
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
  T range_sum(int l,int r) {
    return sum(r-1)-sum(l-1);
  }
};

int example_Seg2D() {
  auto f = [](int x, int y) { return x + y; };
  auto g = [](BIT<int> &k, int x, int y) { return k.sum(y - 1) - k.sum(x - 1); };
  auto h = [](BIT<int> &k, int x, int y) { k.add(x, y); };
  Seg2D<BIT<int>,int> seg(100002, f, g, h, 0);
}


// Two-dimentional (height x width) Segment Tree with Lazy Propagation
// rectangular update, single point query
template< typename structure_t, typename get_t, typename update_t = get_t >
class Seg2DRUPQ {
  using F = function<get_t(get_t, get_t)>;
  using G = function<get_t(structure_t &, int)>;
  using H = function<void(structure_t &, int, int, update_t)>;
  int sz;
  vector<structure_t> seg;
  // Binary-op in Monoid (get_t)
  const F f;
  // Function that get x-th element of structure_t (such BITRangeUpdate, RUP)
  const G g;
  // Function that update the elements in range [x,y) of structure_t by z
  const H h;
  // identity element of Monoid
  const get_t identity;
  // beet[k]: index set of columns with values in rows covered by k-th node
  vector<vector<int>> beet;
  // LL[k][x] (,RR[k][x]): minimum index of left (right) child's beet that is not lower than beet[k][x]
  vector<vector<int>> LL, RR;

  // update element in range [a,b)x[ beet[k][x], beet[k][y] ) by z ([l,r) is the range of rows covered by k-th node)
  void update(int a, int b, int x, int y, update_t z, int k, int l, int r) {
    if(a >= r || b <= l) return;
    if(a <= l && r <= b) return h(seg[k], x, y, z);
    update(a, b, LL[k][x], LL[k][y], z, 2 * k + 0, l, (l + r) >> 1);
    update(a, b, RR[k][x], RR[k][y], z, 2 * k + 1, (l + r) >> 1, r);
  }
  // calculate f in (a, beet[k][x] ) ([l,r) is the range of rows covered by k-th node)
  get_t query(int a, int x, int k, int l, int r) {
    if(r <= a || a + 1 <= l) return identity;
    if(a <= l && r <= a + 1) return g(seg[k], x);
    return f(query(a, LL[k][x], 2 * k + 0, l, (l + r) >> 1),
             query(a, RR[k][x], 2 * k + 1, (l + r) >> 1, r));
  }


  public:
    // let n is height
    Seg2DRUPQ(int n, const F &f, const G &g, const H &h, const get_t &identity)
        : f(f), g(g), h(h), identity(identity) {
      sz = 1;
      while(sz < n) sz <<= 1;
      beet.resize(2 * sz);
      LL.resize(2 * sz);
      RR.resize(2 * sz);
    }
    // predefine [a,b)x[x,y) that is updated
    void preupdate(int a, int b, int x, int y) {
      a += sz;
      b += sz;
      for (int l = a, r = b; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
          beet[l].push_back(x);
          beet[l].push_back(y);
          l++;
        }
        if (r & 1) {
          r--;
          beet[r].push_back(x);
          beet[r].push_back(y);
        }
      }
    }
    // build the two-dimentional segment tree
    void build() {
      // sort and remove duplicate elements
      for(int k = (int) beet.size() - 1; k > 0; k--) {
        sort(begin(beet[k]), end(beet[k]));
        beet[k].erase(unique(begin(beet[k]), end(beet[k])), end(beet[k]));
      }
      for(int k = sz - 1; k > 0; k--) {
        // merge itself and its children's arrays, and remove duplicate elements (sorted)
        beet[k].resize(beet[k].size() + beet[2 * k + 0].size());
        merge(begin(beet[k]), end(beet[k]), begin(beet[2 * k + 0]), end(beet[2 * k + 0]), begin(beet[k]));
        beet[k].resize(beet[k].size() + beet[2 * k + 1].size());
        merge(begin(beet[k]), end(beet[k]), begin(beet[2 * k + 1]), end(beet[2 * k + 1]), begin(beet[k]));
        beet[k].erase(unique(begin(beet[k]), end(beet[k])), end(beet[k]));
        // calculate LL and RR
        LL[k].resize(beet[k].size() + 1);
        RR[k].resize(beet[k].size() + 1);
        int tail1 = 0, tail2 = 0;
        for(int i = 0; i < beet[k].size(); i++) {
          while(tail1 < beet[2 * k + 0].size() && beet[2 * k + 0][tail1] < beet[k][i]) ++tail1;
          while(tail2 < beet[2 * k + 1].size() && beet[2 * k + 1][tail2] < beet[k][i]) ++tail2;
          LL[k][i] = tail1, RR[k][i] = tail2;
        }
        LL[k][beet[k].size()] = (int) beet[2 * k + 0].size();
        RR[k][beet[k].size()] = (int) beet[2 * k + 1].size();
      }
      for(int k = 0; k < beet.size(); k++) {
        seg.emplace_back(structure_t(beet[k].size()));
      }
    }
    // update the elements in range [a,b)x[x,y) by z
    void range_update(int a, int b, int x, int y, update_t z) {
      x = lower_bound(begin(beet[1]), end(beet[1]), x) - begin(beet[1]);
      y = lower_bound(begin(beet[1]), end(beet[1]), y) - begin(beet[1]);
      return update(a, b, x, y, z, 1, 0, sz);
    }
    // get the element in x,y
    get_t point_query(int x, int y) {
      y = lower_bound(begin(beet[1]), end(beet[1]), y) - begin(beet[1]);
      return point_query(x, y, 1, 0, sz);
    }
};

// examples
// Binary Indexed Tree (Range Update and Point Query)
template<typename T>
struct BITRUPQ {
  int n;
  vector<T> dat;
  BITRUPQ(int n) : n(n), dat(n+1,0){}
  void add(int i,T x) {
    for (++i; i<=n; i+=(i&-i)) dat[i] += x;
  }
  // add x to elements in [a,b)
  void range_add(int a, int b, T x) {
    add(a, x);
    add(b, -x);
  }
  T point_query(int i) {
    T res = 0;
    for (++i; i>0; i-=(i&-i))
      res += dat[i];
    return res;
  }
}; // 0-indexed

int example_Seg2DRUPQ() {
  auto f = [](int x, int y) { return x + y; };
  auto g = [](BITRUPQ<int> &k, int x) { return k.point_query(x); };
  auto h = [](BITRUPQ<int> &k, int x, int y, int z) { k.range_add(x, y, z); };
  Seg2DRUPQ<BITRUPQ<int>,int> seg(100002, f, g, h, 0);
}