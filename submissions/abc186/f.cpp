#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


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


int main() {
  int H,W,M;
  cin >> H >> W >> M;
  auto f = [](int x, int y) { return x+y; };
  RMQ<int> seg(200005, f, 0);
  vector<set<int>> RX(200005);
  vector<set<int>> RY(200005);
  rep(i,M) {
    int x,y;
    cin >> x >> y;
    x--; y--;
    RX[x].insert(y);
    RY[y].insert(x);
  }
  rep(i,H) {
    RX[i].insert(W);
  }
  rep(j,W) {
    RY[j].insert(H);
  }
  seg.build();
  ll res = 0;
  int X = *(RY[0].begin());
  int Y = *(RX[0].begin());
  rep(i,X) {
    res += *(RX[i].begin());
  }
  for (int i=X; i<H; i++) {
    seg.update(i,1);
  }
  rep(j,Y-1) {
    int x = *(RY[j+1].begin());
    ll cnt = seg.query(0, x);
    res += cnt;
    for (auto e: RY[j+1]) {
      if (seg[e] == 0)
        seg.update(e,1);
    }
  }
  print(res);
  return 0;
}
