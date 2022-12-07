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
  int H,W;
  cin >> H >> W;
  int m = 100, res = 0;
  vec<vec<int>> A(H, vec<int>(W));
  rep(i,H) {
    rep(j,W) {
      cin >> A[i][j];
      m = min(m, A[i][j]);
    }
  }
  rep(i,H) {
    rep(j,W) {
      res += A[i][j]-m;
    }
  }
  print(res);
  return 0;
}
