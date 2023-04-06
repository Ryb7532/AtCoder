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


int main() {
  ll X,Y,R;
  double x,y,r;
  cin >> x >> y >> r;
  X = round(x * 10000);
  Y = round(y * 10000);
  R = round(r * 10000);
  ll res = 0;
  auto inCircle = [&](ll x, ll y) {
    return (x-X)*(x-X)+(y-Y)*(y-Y) <= R*R;
  };
  for (int x=X-R; x<=X+R; x+=10000) {
    x -= x%10000;
    ll uuy=Y+R+1, luy=Y, uly=Y, lly=Y-R-1;
    if (!inCircle(x, Y))
      continue;
    while (uuy-luy>1) {
      ll muy = (uuy+luy)/2;
      if (inCircle(x, muy)) {
        luy = muy;
      } else {
        uuy = muy;
      }
    }
    while (uly-lly>1) {
      ll mly = (uly+lly)/2;
      if (inCircle(x, mly)) {
        uly = mly;
      } else {
        lly = mly;
      }
    }
    luy += 1e15;
    lly += 1e15;
    res += luy/10000 - lly/10000;
  }
  print(res);
  return 0;
}
