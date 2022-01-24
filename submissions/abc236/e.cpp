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
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  {
    ld l=0,r=1e9+1e-5;
    while(r-l>1e-5) {
      ld m = (r+l)/2;
      vector<vector<ld>> dp(N+1,vector<ld>(2));
      dp[0][0] = 0.0;
      dp[0][1] = 0.0;
      rep(i,N) {
        dp[i+1][0] = dp[i][1];
        dp[i+1][1] = max(dp[i][0],dp[i][1]) + A[i]-m;
      }
      if (max(dp[N][0], dp[N][1]) >= 0)
        l = m;
      else
        r = m;
    }
    print(fix(6) << l);
  }
  {
    ll l=0,r=1e9+1;
    while(r-l>1) {
      ll m = (r+l)/2;
      vector<vector<int>> dp(N+1,vector<int>(2));
      dp[0][0] = 0;
      dp[0][1] = 0;
      rep(i,N) {
        dp[i+1][0] = dp[i][1];
        dp[i+1][1] = max(dp[i][0],dp[i][1]) + (A[i]<m ? -1 : 1);
      }
      if (max(dp[N][0], dp[N][1]) > 0)
        l = m;
      else
        r = m;
    }
    print(l);
  }
  return 0;
}
