#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__, rrep3, rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


// Task: Subset Sum Problem
// Binary Indexed Tree (Point Update and Range Query)
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
  T range_sum(int l,int r) { // [l,r)
    return sum(r-1)-sum(l-1);
  }
}; // 0-indexed


int main() {
  ll N;
  cin >> N;
  vector<int> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  int l = 1, r = 1e9+1;
  while (r-l > 1) {
    int m = (r+l)/2;
    int s = 0;
    ll cnt = 0;
    BIT<ll> bit(2e5+1);
    rep(i,N) {
      bit.add(s+1e5,1);
      if (A[i] >= m)
        s++;
      else
        s--;
      cnt += bit.sum(s+1e5);
    }
    if (2*cnt >= N*(N+1)/2)
      l = m;
    else
      r = m;
  }
  print(l);
  return 0;
}
