#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int H,W;
  cin >> H >> W;
  vec<vec<ll>> A(H, vec<ll>(W));
  rep(i,H) {
    rep(j,W) {
      cin >> A[i][j];
    }
  }
  bool check = true;
  rep(i1,H) {
    for (int i2=i1+1; i2<H; i2++) {
      rep(j1,W) {
        for (int j2=j1+1; j2<W; j2++) {
          if (A[i1][j1]+A[i2][j2]>A[i1][j2]+A[i2][j1])
            check = false;
        }
      }
    }
  }
  print((check ? Yes : No));
  return 0;
}
