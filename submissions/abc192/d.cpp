#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  string X;
  ll M;
  cin >> X >> M;
  int x = X.size();
  int d = 0;
  rep(i,x) {
    d = max(d,X[i]-'0');
  }
  if (x == 1) {
    print((M<d ? 0 : 1));
    return 0;
  }
  ll u = M+1, l = d;
  while (u-l > 1) {
    ll h = (u+l)/2;
    ll X_h = 0;
    bool ok = true;
    rep(i,x) {
      if (X_h > M/h) {
        ok = false;
        break;
      }
      X_h *= h;
      X_h += X[i]-'0';
    }
    if (X_h > M)
      ok = false;
    if (ok) {
      l = h;
    } else {
      u = h;
    }
  }
  print(l-d);
  return 0;
}
