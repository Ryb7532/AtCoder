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
  BIT_RUPQ<ll> bit(N);
  rep(i,N) {
    ll a;
    cin >> a;
    bit.range_add(i,i+1,a);
  }
  rep(M) {
    int b;
    cin >> b;
    ll c = bit.point_query(b);
    bit.range_add(b,b+1,-c);
    bit.range_add(0,N,c/N);
    c %= N;
    if (b+c+1 < N) {
      bit.range_add(b+1,b+c+1,1);
    } else {
      bit.range_add(b+1,N,1);
      bit.range_add(0,b+c-N+1,1);
    }
  }
  rep(i,N) {
    cout << bit.point_query(i) << " ";
  }
  cout << endl;
  return 0;
}