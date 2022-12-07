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
  int Q;
  cin >> Q;
  rep(_,Q) {
    ll A,B;
    cin >> A >> B;
    if (A>B)
      swap(A,B);
    ll N = A*B-1;
    ll l=1, u=1e9+5;
    while(u-l>1) {
      ll m = (u+l)/2;
      if (m*m <= N)
        l = m;
      else
        u = m;
    }
    ll res = 2*l;
    if (l*(l+1) > N)
      res--;
    if (A<=l)
      res--;
    print(res);
  }
  return 0;
}
