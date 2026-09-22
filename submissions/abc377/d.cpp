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


int main() {
  int N;
  ll M;
  scan(N,M);
  vector<int> L(N+1), R(N+1), idx(N+1);
  rep(i,N) {
    scan(L[i], R[i]);
    idx[i] = i;
  }
  L[N] = M; R[N] = M+1; idx[N] = N;
  sort(all(idx), [&](int a, int b) {
    if (L[a] != L[b]) return L[a] < L[b];
    return R[a] > R[b];
  });
  RMQ<ll> rmq(N+1, [](ll a, ll b) { return min(a, b); }, M+1);
  rep(i,N+1) {
    rmq.set(i, R[idx[i]]);
  }
  rmq.build();
  ll res = 0;
  ll prev_l = 0;
  rep(i,N+1) {
    int j = idx[i];
    ll l = L[j], r = rmq.query(i, N+1);
    res += (l - prev_l - 1) * (l - prev_l) / 2 + (l - prev_l) * (r - l);
    prev_l = l;
  }
  print(res);
  return 0;
}