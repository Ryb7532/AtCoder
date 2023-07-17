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
  ll A,B;
  cin >> A >> B;
  auto f = [&](ll t) { return (ld)A/sqrt(t+1)+(ld)B*t; };
  ll l = 0, r = 1e18+5;
  while (r-l > 2) {
    ll m1 = (r+2*l)/3;
    ll m2 = (2*r+l)/3;
    if (f(m1) < f(m2))
      r = m2;
    else
      l = m1;
  }
  print(fix(10) << min(f(l), min(f(l+1), f(r))));
  return 0;
}
