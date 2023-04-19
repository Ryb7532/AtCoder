#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(int)n; i++)
#define rrep(i,n) for (int i=(int)n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int N;
  cin >> N;
  vector<ll> A(N), B(N);
  ll sum = 0;
  rep(i,N) {
    cin >> A[i];
    sum += A[i];
  }
  rep(i,N) {
    cin >> B[i];
    sum += B[i];
  }
  vector<vector<ll>> dp(N, vector<ll>(4, -1e18));
  dp[0][0] = 0;
  dp[0][3] = A[0];
  rep(i,N-1) {
    rep(j,2) {
      dp[i+1][2*j] = max(dp[i][2*j], dp[i][2*j+1]+B[i]);
      dp[i+1][2*j+1] = max(dp[i][2*j]+B[i], dp[i][2*j+1])+A[i+1];
    }
  }
  print(sum-max(max(dp[N-1][0], dp[N-1][1]+B[N-1]), max(dp[N-1][2]+B[N-1], dp[N-1][3])));
  return 0;
}
