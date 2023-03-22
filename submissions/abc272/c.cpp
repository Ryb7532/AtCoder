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
  int N;
  cin >> N;
  vector<ll> O,E;
  int o = 0, e = 0;
  rep(i,N) {
    ll A;
    cin >> A;
    if (A%2) {
      O.push_back(A);
      o++;
    } else {
      E.push_back(A);
      e++;
    }
  }
  sort(rall(O));
  sort(rall(E));
  ll res = -1;
  if (o >= 2) {
    res = max(res, O[0]+O[1]);
  }
  if (e >= 2) {
    res = max(res, E[0]+E[1]);
  }
  print(res);
  return 0;
}
