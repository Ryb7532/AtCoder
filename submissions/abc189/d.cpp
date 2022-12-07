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
  vec<string> S(N);
  rep(i,N)
    cin >> S[i];
  vec<vec<ll>> dp(N+1, vec<ll>(2,0));
  dp[0][0] = 1;
  dp[0][1] = 1;
  rep(i,N) {
    if (S[i] == "AND") {
      dp[i+1][0] = dp[i][0]*2 + dp[i][1];
      dp[i+1][1] = dp[i][1];
    } else {
      dp[i+1][0] = dp[i][0];
      dp[i+1][1] = dp[i][1]*2 + dp[i][0];
    }
  }
  print(dp[N][1]);
  return 0;
}
