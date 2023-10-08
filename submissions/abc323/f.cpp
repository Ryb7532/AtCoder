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

int main() {
  ll Xa, Ya, Xb, Yb, Xc, Yc;
  cin >> Xa >> Ya >> Xb >> Yb >> Xc >> Yc;
  ll res = 1e18;
  rep(_,2) {
    ll tmp = 1e18;
    if (Xc < Xb) {
      if (Xa <= Xb || Ya != Yb) {
        tmp = abs(Xb+1-Xa) + min(abs(Yb+1-Ya), abs(Yb-1-Ya)) + 1 + abs(Xc-Xb);
      } else {
        tmp = abs(Xc+1-Xa);
      }
      if (Yc != Yb) {
        tmp += 2 + abs(Yc-Yb);
      }
    } else if (Xc > Xb) {
      if (Xa >= Xb || Ya != Yb) {
        tmp = abs(Xb-1-Xa) + min(abs(Yb+1-Ya), abs(Yb-1-Ya)) + 1 + abs(Xc-Xb);
      } else {
        tmp = abs(Xc-1-Xa);
      }
      if (Yc != Yb) {
        tmp += 2 + abs(Yc-Yb);
      }
    }
    res = min(res, tmp);
    swap(Xa, Ya);
    swap(Xb, Yb);
    swap(Xc, Yc);
  }
  print(res);
  return 0;
}