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
  vector<int> X(3), Y(3);
  rep(i,3) {
    cin >> X[i] >> Y[i];
  }
  int xid, yid;
  if (X[0] == X[1]) {
    xid = 2;
  } else if (X[0] == X[2]) {
    xid = 1;
  } else {
    xid = 0;
  }
  if (Y[0] == Y[1]) {
    yid = 2;
  } else if (Y[0] == Y[2]) {
    yid = 1;
  } else {
    yid = 0;
  }
  print(X[xid] << " " << Y[yid]);
  return 0;
}
