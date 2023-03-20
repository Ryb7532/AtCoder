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
  int X,Y,Z;
  cin >> X >> Y >> Z;
  int res = -1;
  if (abs(X)+abs(Y) == abs(X-Y) || abs(X) < abs(Y)) {
    res = abs(X);
  } else if (abs(Z)+abs(Y) == abs(Z-Y) || abs(Z) < abs(Y)) {
    res = abs(Z) + abs(Z-X);
  }
  print(res);
  return 0;
}
