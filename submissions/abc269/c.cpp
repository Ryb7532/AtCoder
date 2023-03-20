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
  ll N;
  cin >> N;
  vector<int> B;
  rep(i,60) {
    if (N & (1LL<<i))
      B.push_back(i);
  }
  int L = B.size();
  rep(i,(1LL<<L)) {
    ll x = 0;
    rep(j,L) {
      if (i & (1LL<<j))
        x += (1LL<<B[j]);
    }
    print(x);
  }
  return 0;
}
