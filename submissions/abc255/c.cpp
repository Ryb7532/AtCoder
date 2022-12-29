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

ll X, A, D, N;
ll dist(ll n) {
  return abs(X - (A + D * n));
}


int main() {
  cin >> X >> A >> D >> N;
  ll l = 0, r = N;
  while (r-l > 1) {
    ll ml = (2 * l + r) / 3;
    ll mr = (l + 2 * r) / 3;
    if (dist(ml) > dist(mr)) {
      l = ml+1;
    } else {
      r = mr;
    }
  }
  print(dist(l));
  return 0;
}
