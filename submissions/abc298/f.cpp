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
  cin >> N;
  vector<pair<pair<int,int>,int>> RC(N);
  vector<ll> X(N);
  map<int,ll> RS, CS;
  set<int> usedC;
  int id = 0;
  rep(i,N) {
    int r,c;
    ll x;
    cin >> r >> c >> x;
    X[i] = x;
    RC[i] = {{r, c}, i};
    RS[r] += x;
    CS[c] += x;
    usedC.insert(c);
  }
  map<int,int> C2cid, cid2C;
  int cid = 0;
  for (int c: usedC) {
    C2cid[c] = cid;
    cid2C[cid] = c;
    cid++;
  }
  sort(all(RC));
  ll res = 0;
  using Monoid = ll;
  auto f = [](ll a, ll b) { return max(a,b); };
  RMQ<Monoid> seg(cid, f, 0);
  rep(i,cid) {
    seg.set(i, CS[cid2C[i]]);
  }
  seg.build();
  while (id < N) {
    int lid = id;
    int r = RC[id].first.first;
    while (id < N && RC[id].first.first == r) {
      id++;
    }
    for (int i=lid; i<id; i++) {
      int c = RC[i].first.second;
      ll nv = seg[C2cid[c]] - X[RC[i].second];
      seg.update(C2cid[c], nv);
    }
    res = max(res, RS[r] + seg.query(0,cid));
    for (int i=lid; i<id; i++) {
      int c = RC[i].first.second;
      ll nv = seg[C2cid[c]] + X[RC[i].second];
      seg.update(C2cid[c], nv);
    }
  }
  print(res);
  return 0;
}
