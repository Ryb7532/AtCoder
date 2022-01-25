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
  int H,W,A,B;
  cin >> H >> W >> A >> B;
  rep(i,B) {
    rep(j,A) {
      cout << '0';
    }
    rep(j,W-A) {
      cout << '1';
    }
    cout << endl;
  }
  rep(i,H-B) {
    rep(j,A) {
      cout << '1';
    }
    rep(j,W-A) {
      cout << '0';
    }
    cout << endl;
  }
  return 0;
}
