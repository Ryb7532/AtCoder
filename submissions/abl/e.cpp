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
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

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

const ll mod = 998244353;
struct mint {
  ll x;
  mint(ll x=0) : x((x%mod+mod)%mod) {}
  mint &operator+=(const mint &p) { if((x += p.x) >= mod) x -= mod; return *this; }
  mint &operator-=(const mint &p) { if((x += mod - p.x) >= mod) x -= mod; return *this; }
  mint &operator*=(const mint &p) { x = x * p.x % mod; return *this; }
  mint &operator/=(const mint &p) { *this *= p.inverse(); return *this; }
  mint operator-() const { return mint(-x); }
  mint operator+(const mint &p) const { return mint(*this) += p; }
  friend mint operator+(const int &c,const mint &p) { return mint(c) += p; }
  mint operator-(const mint &p) const { return mint(*this) -= p; }
  friend mint operator-(const int &c,const mint &p) { return mint(c) -= p; }
  mint operator*(const mint &p) const { return mint(*this) *= p; }
  friend mint operator*(const int &c,const mint &p) { return mint(c) *= p; }
  mint operator/(const mint &p) const { return mint(*this) /= p; }
  friend mint operator/(const int &c,const mint &p) { return mint(c) /= p; }
  bool operator==(const mint &p) const { return x == p.x; }
  friend bool operator==(const int &c,const mint &p) { return mint(c) == p; }
  bool operator!=(const mint &p) const { return x != p.x; }
  friend bool operator!=(const int &c, const mint &p) { return mint(c) != p; }
  mint inverse() const {
    ll a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return mint(u);
  }
  mint pow(ll n) const {
    mint ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os,const mint &p) { return os << p.x; }
  friend istream &operator>>(istream &is,mint &a) {
    ll t;
    is >> t;
    a = mint(t);
    return (is);
  }
};


int main() {
  int N,Q;
  cin >> N >> Q;
  using OperatorMonoid = pair<int,int>;
  auto f = [](mint a, mint b, int la, int lb) {
    return a + b * mint(10).pow(la);
  };
  auto g = [](mint data, OperatorMonoid lazy, int l) {
    if (lazy.first < 0)
      return data;
    mint ndata = 0, x = lazy.second, dig = 10;
    while (l > 0) {
      if (l&1) {
        ndata *= dig;
        ndata += x;
      }
      l >>= 1;
      x += x * dig;
      dig *= dig;
    }
    return ndata;
  };
  auto h = [](OperatorMonoid a, OperatorMonoid b) {
    if (a.first < b.first)
      return b;
    else
      return a;
  };
  RUQ<mint, OperatorMonoid> seg(N, f, g, h, mint(0), {-1,0});
  rep(i,N) {
    seg.set(i,mint(1));
  }
  seg.build();
  rep(i,Q) {
    int L,R,D;
    cin >> L >> R >> D;
    seg.update(N-R,N+1-L,{i,D});
    print(seg.query(0,N));
  }
  return 0;
}