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
#define printYorN(f) cout << (f ? Yes : No) << endl


int main() {
  int N,K,D;
  cin >> N >> K >> D;
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(K+2, vector<ll>(D, -1)));
  dp[0][0][0] = 0;
  rep(i,N) {
    ll a = A[i];
    rep(j,K+1) {
      rep(k,D) {
        if (dp[i][j][k] == -1)
          continue;
        dp[i+1][j+1][(k+a)%D] = max(dp[i+1][j+1][(k+a)%D], dp[i][j][k]+a);
        dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
      }
    }
  }
  print(dp[N][K][0]);
  return 0;
}
