#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())

template<typename Monoid>
struct Seg {
  //Binary-op that merges the elements of two sub-arrays
  using F = function<Monoid(Monoid, Monoid)>;
  int sz;
  vector<Monoid> seg;
  const F f;
  const Monoid M1; // identity element of monoid
  Seg(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz<n) sz <<= 1;
    seg.assign(2*sz, M1);
  }
  void set(int k, const Monoid &x) {
    seg[k+sz] = x;
  }
  void build() {
    for(int k=sz-1; k>0; k--) {
      seg[k] = f(seg[2*k], seg[2*k+1]);
    }
  }
  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k>>=1) {
      seg[k] = f(seg[2*k], seg[2*k+1]);
    }
  }
  //[a,b)
  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }
  Monoid operator[](const int &k) const {
    return seg[k+sz];
  }
  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while(a<sz) {
      Monoid nxt = type ? f(seg[2*a+type], M) : f(M, seg[2*a+type]);
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
      if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        Monoid nxt = f(L, seg[a]);
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
      if(check(f(seg[1], R))) return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        Monoid nxt = f(seg[--b], R);
        if(check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};


int main() {
  int N,Q;
  cin >> N >> Q;
  vector<int> c(N);
  vector<int> p[N];
  vector<pii> q[N];
  vector<int> ans(Q);
  rep(i,N) {
    cin >> c[i];
    c[i]--;
  }
  rep(i,N) {
    p[c[i]].push_back(i);
  }
  rep(i,Q) {
    int l,r;
    cin >> l >>r;
    l--;
    q[l].push_back({r,i});
  }
  function<int(int,int)> f = [&](int a,int b){return a+b;};
  Seg<int> seg(N,f,0);
  rep(i,N) {
    if (!p[i].empty())
      seg.set(p[i][0],1);
  }
  seg.build();
  rep(i,N) {
    for (auto &e : q[i]) {
      ans[e.second] = seg.query(i,e.first);
    }
    seg.update(p[c[i]][0],0);
    p[c[i]].erase(p[c[i]].begin());
    if (!p[c[i]].empty())
      seg.update(p[c[i]][0],1);
  }
  rep(i,Q) {
    print(ans[i]);
  }
  return 0;
}
