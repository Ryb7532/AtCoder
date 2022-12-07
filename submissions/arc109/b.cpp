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
  ll n;
  cin >> n;
  ll l=1,u=2e9;
  while (u-l>1) {
    ll m = (u+l)/2;
    if (2*n>=(m+2)*(m-1))
      l = m;
    else
      u = m;
  }
  print(n+1-l);
  return 0;
}
