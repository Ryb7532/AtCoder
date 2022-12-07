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
  int N,M;
  cin >> N >> M;
  vec<int> A(N),B(M);
  rep(i,N)
    cin >> A[i];
  rep(i,M)
    cin >> B[i];
  vec<vec<int>> dp(N+1, vec<int>(M+1,0));
  rep(i,N+1) {
    rep(j,M+1) {
      if (i == 0 || j == 0) {
        dp[i][j] = i+j;
      } else {
        dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+(A[i-1]!=B[j-1]));
      }
    }
  }
  print(dp[N][M]);
  return 0;
}
