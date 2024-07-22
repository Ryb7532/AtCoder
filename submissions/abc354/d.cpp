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
#define Yes "Yes"
#define No "No"
#define printyn(f) cout << ((f) ? Yes : No) << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}
template<typename... Args> void print(const Args... args) {(cout << ... << (cout << ' ', args)) << endl;}

int main() {
  ll area[2][4] = {
    {2,1,0,1},
    {1,2,1,0}
  };
  ll A,B,C,D;
  cin >> A >> B >> C >> D;
  ll res = 0;
  if (A < 0) {
    ll k = (abs(A)+3)/4;
    A += 4*k;
    C += 4*k;
  }
  if (B < 0) {
    ll k = (abs(B)+1)/2;
    B += 2*k;
    D += 2*k;
  }
  A += 4;
  C += 4;
  B += 2;
  D += 2;
  rep(x,4) {
    rep(y,2) {
      ll cx = (C-x-1)/4 - (A-x-1)/4;
      ll cy = (D-y-1)/2 - (B-y-1)/2;
      res += area[y][x] * cx * cy;
    }
  }
  print(res);
  return 0;
}