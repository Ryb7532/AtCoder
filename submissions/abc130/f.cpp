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
  int N;
  cin >> N;
  string dir = "RLUD";
  ld xmax, xmin, ymax, ymin;
  xmax = ymax = -1e9;
  xmin = ymin = 1e9;
  vector<pair<ld,ld>> D(4, {1e9, -1e9});
  rep(i,N) {
    ld x,y;
    char d;
    cin >> x >> y >> d;
    int did;
    rep(j,4) {
      if (dir[j] == d)
        did = j;
    }
    if (did < 2) {
      D[did].first = min(D[did].first, x);
      D[did].second = max(D[did].second, x);
      ymin = min(ymin, y);
      ymax = max(ymax, y);
    } else {
      D[did].first = min(D[did].first, y);
      D[did].second = max(D[did].second, y);
      xmin = min(xmin, x);
      xmax = max(xmax, x);
    }
  }
  auto f = [&](ld t) {
    ld x = max(xmax, max(D[0].second+t, D[1].second-t)) - min(xmin, min(D[0].first+t, D[1].first-t));
    ld y = max(ymax, max(D[2].second+t, D[3].second-t)) - min(ymin, min(D[2].first+t, D[3].first-t));
    return x*y;
  };
  ld l = 0.0, u = 1e9;
  while (u-l>1e-10) {
    ld m0 = (2*l+u)/3, m1 = (l+2*u)/3;
    if (f(m0) <= f(m1))
      u = m1;
    else
      l = m0;
  }
  ld res = f(u);
  rep(i,1e6) {
    res = min(res, f(l+(u-l)*i/1e6));
  }
  print(fix(10) << res);
  return 0;
}