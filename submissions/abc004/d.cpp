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
  int R,G,B;
  cin >> R >> G >> B;
  ll res = 1e9;
  for (int i=-500; i<500; i++) {
    ll cost = 0;
    if (i+G-1<0) {
      cost += G*abs(i+G);
      cost += G*(G+1)/2;
    } else if (i>0) {
      cost += G*(i-1);
      cost += G*(G+1)/2;
    } else {
      cost += -i*(-i+1)/2;
      cost += (i+G-1)*(i+G)/2;
    }
    if (i<=-100) {
      cost += R*(-100-i);
      cost += R*(R+1)/2;
    } else {
      int r = min(R/2, i+99);
      cost += r*(r+1)/2;
      cost += (R-r-1)*(R-r)/2;
    }
    if (i+G>100) {
      cost += B*(i+G-101);
      cost += B*(B+1)/2;
    } else {
      int l = min(B/2, 100-i-G);
      cost += l*(l+1)/2;
      cost += (B-l-1)*(B-l)/2;
    }
    res = min(res, cost);
  }
  print(res);
  return 0;
}
