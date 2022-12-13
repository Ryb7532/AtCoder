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
  long K;
  cin >> N >> K;
  vector<vector<long>> A(N,vector<long>(2));
  rep(j,2) {
    rep(i,N) {
      cin >> A[i][j];
    }
  }
  vector<vector<bool>> dp(N,vector<bool>(2, false));
  dp[0][0] = true;
  dp[0][1] = true;
  rep(i,N-1) {
    rep(j,2) {
      rep(k,2) {
        long sub = abs(A[i][j] - A[i+1][k]);
        if (sub <= K && dp[i][j]) {
          dp[i+1][k] = true;
        }
      }
    }
  }
  print((dp[N-1][0]||dp[N-1][1] ? Yes : No));
  return 0;
}
