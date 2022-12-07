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
  int N,X;
  cin >> N >> X;
  vector<int> A(N), B(N);
  rep(i,N) {
    cin >> A[i] >> B[i];
  }
  vector<vector<bool>> dp(N+1, vector<bool>(X+1, false));
  dp[0][0] = true;
  rep(i,N) {
    rep(j,X+1) {
      if (j+A[i]>X)
        break;
      dp[i+1][j+A[i]] = dp[i+1][j+A[i]] || dp[i][j];
      if (j+B[i]<=X) {
        dp[i+1][j+B[i]] = dp[i+1][j+B[i]] || dp[i][j];
      }
    }
  }
  print((dp[N][X] ? Yes : No));
  return 0;
}
