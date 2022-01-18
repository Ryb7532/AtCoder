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
  ll x,y;
  cin >> x >> y;
  ll res;
  if (x<=y) {
    res = y-x;
  } else {
    res = x-y+2;
  }
  if ((x<0 && y>0) || (y<0 && x>0) || x==0 || y==0) {
    res = min(res, abs(abs(x)-abs(y))+1);
  }
  print(res);
  return 0;
}
