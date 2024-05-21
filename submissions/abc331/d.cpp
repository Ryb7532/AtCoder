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
#define fore(e,v) for (auto &e: v)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

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
    if (r <= l) return 0;
    return sum(r-1)-sum(l-1);
  }
}; // 0-indexed

int main() {
  int N,Q;
  cin >> N >> Q;
  vector<BIT<ll>> bits;
  vector<vector<ll>> cnt(N+1, vector<ll>(N+1,0));
  rep(i,N) {
    string S;
    cin >> S;
    bits.emplace_back(BIT<ll>(N+1));
    rep(j,N) {
      if (S[j] == 'B')
        bits[i].add(j+1, 1);
    }
  }
  rep(i,N) {
    rep(j,N+1) {
      cnt[i+1][j] = cnt[i][j] + bits[i].sum(j);
    }
  }
  rep(_,Q) {
    ll A,B,C,D;
    cin >> A >> B >> C >> D;
    C -= A / N * N;
    A -= A / N * N;
    D -= B / N * N;
    B -= B / N * N;
    ll res = cnt[C%N+1][D%N+1] + cnt[C%N+1][N] * (D/N) - cnt[C%N+1][B];
    res -= cnt[A][D%N+1] + cnt[A][N] * (D/N) - cnt[A][B];
    res += (cnt[N][D%N+1] + cnt[N][N] * (D/N) - cnt[N][B]) * (C/N);
    print(res);
  }
  return 0;
}