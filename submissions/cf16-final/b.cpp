#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
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
  ll l=0, u=N;
  while (u-l>1) {
    ll m = (u+l)/2;
    if (m*(m+1)/2 >= N) {
      u = m;
    } else {
      l = m;
    }
  }
  int skip = u*(u+1)/2-N;
  rep(i,u) {
    if (i+1 == skip)
      continue;
    print(i+1);
  }
  return 0;
}
