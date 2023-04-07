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


// Task: Compute GCD(a,b)(=d) and a particular solution of a * x + b * y = d
// Extended Euclidean Algorithm
ll extGCD(ll a, ll b, ll &x, ll &y) {
  if (b==0) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = extGCD(b, a%b, y, x);
  y -= a/b*x;
  return d;
}


int main() {
  int T;
  cin >> T;
  rep(_,T) {
    ll X,Y,P,Q;
    cin >> X >> Y >> P >> Q;
    ll A,B,x,y,A_,B_;
    A = X+Y;
    B = P+Q;
    A_ = 2*A;
    ll d = extGCD(A_, B, x, y);
    A_ /= d;
    B_ = B/d;
    ll res = -1;
    for (ll k=(P-A)/d; d*k<B-X; k++) {
      if (P-A >= d*k)
        continue;
      ll n = k*x, m = -k*y;
      if (n < 0 || m < 0) {
        ll l = max((-n+B_-1)/(B_), (-m+A_-1)/A_);
        n += l*B_;
        m += l*A_;
      }
      ll l = min(n/B_, m/A_);
      n -= l*B_;
      m -= l*A_;
      if (res == -1)
        res = max(2*(X+Y)*n+X, (P+Q)*m+P);
      else
        res = min(res, max(2*(X+Y)*n+X, (P+Q)*m+P));
    }
    if (res == -1)
      print("infinity");
    else
      print(res);
  }
  return 0;
}
