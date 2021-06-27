#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  int X,Y,N;
  cin >> X >> Y >> N;
  Y += X;
  vector<int> t(N+1);
  vector<int> h(N+1);
  rep1(i,N) {
    cin >> t[i] >> h[i];
  }
  int ans = 0;
  int dp[N+1][Y+1][X+1];
  rep(n,N+1) rep(y,Y+1) rep(x,X+1) dp[n][y][x] = -1;
  dp[0][0][0] = 0;
  rep1(n,N) {
    rep(y,Y+1) {
      rep(x,X+1) {
          dp[n][y][x] = dp[n-1][y][x];
      }
      if (y-t[n]<0)
        continue;
      rep1(x,X) {
        if (dp[n-1][y-t[n]][x-1]<0)
          continue;
        dp[n][y][x] = max(dp[n][y][x], dp[n-1][y-t[n]][x-1]+h[n]);
      }
    }
  }
  rep(y,Y+1) rep(x,X+1) ans = max(ans,dp[N][y][x]);
  print(ans);
  return 0;
}
