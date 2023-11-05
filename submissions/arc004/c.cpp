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

ll GCD(ll a, ll b) {
  while (b != 0) {
    swap(a,b);
    b %= a;
  }
  return a;
}

int main() {
  ll X,Y;
  char c;
  cin >> X >> c >> Y;
  ll g = GCD(X,Y);
  X /= g;
  Y /= g;
  bool flag = true;
  for (ll k=max((4*X-2*Y)/Y/Y, 1ll); k<=(4*X+2*Y)/Y/Y; k++) {
    if (k*Y%2 || (k%2 && X%2))
      continue;
    ll N = k*Y/2, M;
    ll s,t;
    s = 2*X/Y;
    t = Y*(N+1-s) - 2*X%Y;
    if (t%2) {
      if (k%4)
        continue;
      M = k/4*t;
    } else {
      t /= 2;
      if (t%2) {
        if (k%2)
          continue;
        M = k/2*t;
      } else {
        M = k*(t/2);
      }
    }
    if (M > N || M <= 0)
      continue;
    print(N << " " << M);
    flag = false;
  }
  if (flag)
    print("Impossible");
  return 0;
}