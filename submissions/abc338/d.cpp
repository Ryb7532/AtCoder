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
#define rrep1(n) rrep2(_,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define out1(a) cout << (a) << endl
#define out2(a,b) cout << (a) << " " << (b) << endl
#define out3(a,b,c) cout << (a) << " " << (b) << " " << (c) << endl
#define print(...) GET_MACRO(__VA_ARGS__,out3,out2,out1)(__VA_ARGS__)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyn(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

// Binary Indexed Tree (Range Update and Point Query)
template<typename T>
struct BIT_RUPQ {
  int n;
  vector<T> dat;
  BIT_RUPQ(int n) : n(n), dat(n+1,0){}
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

int main() {
  int N,M;
  cin >> N >> M;
  vector<int> X(M);
  BIT_RUPQ<ll> bit(N);
  ll res = 0;
  cin >> X[0];
  X[0]--;
  rep(i,1,M) {
    cin >> X[i];
    X[i]--;
    int l = min(X[i], X[i-1]);
    int r = max(X[i], X[i-1]);
    int d = r-l;
    if (d >= N-d) {
      bit.range_add(0, l, 2*d-N);
      bit.range_add(r, N, 2*d-N);
      res += N-d;
    } else {
      bit.range_add(l, r, N-2*d);
      res += d;
    }
  }
  ll m = 1e18;
  rep(i,N) {
    chmin(m, bit.point_query(i));
  }
  print(res+m);
  return 0;
}