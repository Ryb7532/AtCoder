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
  vec<string> S(H);
  rep(i,H) {
    cin >> S[i];
  }
  int res = 0;
  rep(i,H-1) {
    rep(j,W-1) {
      int cnt = 0;
      rep(k,2)
        rep(l,2)
          cnt += (S[i+k][j+l] == '#');
      if (cnt%2)
        res++;
    }
  }
  print(res);
  return 0;
}
