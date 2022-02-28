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
  int T;
  cin >> T;
  rep(_,T) {
    int N,M;
    cin >> N >> M;
    vector<ll> x(N), y(N);
    rep(i,N) {
      cin >> x[i] >> y[i];
    }
    ll sum = 0;
    vector<vector<ll>> dp(N+1,vector<ll>(2,-10));
    dp[0][0] = 0;
    rep(i,N) {
      dp[i+1][0] = dp[i][0] + sum*y[i] + x[i]*y[i]*(y[i]+1)/2;
      if (x[i]>=0) {
        dp[i+1][1] = max(dp[i][1], dp[i+1][0]);
      } else {
        int p = min(max((ll)1, sum/(-x[i])), y[i]);
        dp[i+1][1] = max(dp[i][1], dp[i][0] + sum*p + x[i]*p*(p+1)/2);
      }
      sum += x[i] * y[i];
    }
    print(dp[N][1]);
  }
  return 0;
}
