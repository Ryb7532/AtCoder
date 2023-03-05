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
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  ld A,B;
  cin >> A >> B;
  const ld pi = M_PI;
  if (A < B)
    swap(A,B);
  ld l=0, r=pi/6;
  while (r-l > 1e-12) {
    ld ml, mr;
    ml = (r+2*l)/3;
    mr = (2*r+l)/3;
    ld l_ml = min(B / cos(ml), A / cos(pi/6-ml));
    ld l_mr = min(B / cos(mr), A / cos(pi/6-mr));
    if (l_ml < l_mr)
      l = ml;
    else
      r = mr;
  }
  ld res = min(B / cos(l), A / cos(pi/6-l));
  print(fix(10) << res);
  return 0;
}
