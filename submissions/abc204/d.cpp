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
  int N;
  cin >> N;
  vec<int> T(N);
  int sum = 0;
  rep(i,N) {
    cin >> T[i];
    sum += T[i];
  }
  vec<vec<bool>> dp(N+1, vec<bool>(sum+1,false));
  dp[0][0] = true;
  rep(i,N) {
    rep(j,sum+1) {
      dp[i+1][j] = dp[i][j];
      if (j-T[i]>=0)
        dp[i+1][j] = dp[i+1][j] || dp[i][j-T[i]];
    }
  }
  int res = sum;
  rep(i,sum+1) {
    if (dp[N][i])
      res = min(res, max(i,sum-i));
  }
  print(res);
  return 0;
}
