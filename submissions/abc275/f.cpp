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
  int N,M;
  cin >> N >> M;
  vector<int> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  const int maxC = 1e5;
  vector<vector<int>> dp(M+1, vector<int>(2,maxC));
  dp[0][1] = 0;
  rep(i,N) {
    int a = A[i];
    for (int j=M; j>=0; j--) {
      dp[j][0] = min(dp[j][0], dp[j][1]+1);
      if (j-a >= 0) {
        dp[j][1] = min(dp[j-a][1], dp[j-a][0]);
      } else {
        dp[j][1] = maxC;
      }
    }
  }
  rep(i,M) {
    if (dp[i+1][0] == maxC && dp[i+1][1] == maxC)
      print(-1);
    else
      print(min(dp[i+1][0], dp[i+1][1]));
  }
  return 0;
}
