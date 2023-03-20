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


int main() {
  int N,K;
  cin >> N >> K;
  vector<int> A(K);
  rep(i,K) {
    cin >> A[i];
  }
  vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(2, vector<int>(2,0)));
  rep(i,N+1) {
    rep(j,2) {
      int smax = 0, p = 0;
      for (int a: A) {
        if (a > i) {
          break;
        }
        if (smax <= dp[i-a][1-j][j] + a) {
          smax = dp[i-a][1-j][j] + a;
          p = dp[i-a][1-j][1-j];
        }
      }
      dp[i][j][j] = smax;
      dp[i][j][1-j] = p;
    }
  }
  print(dp[N][0][0]);
  return 0;
}
