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
  vec<string> A(H);
  vec<vec<int>> P(H, vec<int>(W));
  vec<vec<int>> dp(H, vec<int>(W));
  rep(i,H) {
    cin >> A[i];
  }
  rep(i,H) {
    rep(j,W) {
      if ((i+j)%2==0) {
        if (A[i][j]=='+')
          P[i][j] = -1;
        else
          P[i][j] = 1;
      } else {
        if (A[i][j]=='+')
          P[i][j] = 1;
        else
          P[i][j] = -1;
      }
    }
  }
  dp[H-1][W-1] = 0;
  for (int i=H-2; i>=0; i--) {
    dp[i][W-1] = dp[i+1][W-1] + P[i][W-1];
  }
  for (int j=W-2; j>=0; j--) {
    dp[H-1][j] = dp[H-1][j+1] + P[H-1][j];
  }
  for (int i=H-2; i>=0; i--) {
    for (int j=W-2; j>=0; j--) {
      if ((i+j)%2==0) {
        dp[i][j] = max(dp[i+1][j], dp[i][j+1]) + P[i][j];
      } else {
        dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + P[i][j];
      }
    }
  }
  if (dp[0][0]>0) {
    print("Takahashi");
  } else if (dp[0][0]==0) {
    print("Draw");
  } else {
    print("Aoki");
  }
  return 0;
}
