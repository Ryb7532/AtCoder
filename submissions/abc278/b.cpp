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
  int H,M;
  cin >> H >> M;
  while (true) {
    int H_,M_;
    H_ = (H/10)*10 + M/10;
    M_ = (H%10)*10 + M%10;
    if (0 <= H_ && H_ < 24 && 0 <= M_ && M_ < 60) {
      print(H << " " << M);
      break;
    }
    M++;
    if (M == 60) {
      H++;
      M = 0;
    }
    if (H == 24) {
      H = 0;
    }
  }
  return 0;
}
