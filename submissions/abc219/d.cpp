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

const int MAX = 500;

int main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  vec<pair<int,int>> A(N);
  rep(i,N) {
    cin >> A[i].first >> A[i].second;
  }
  vec<vec<vec<int>>> dp(N+1, vec<vec<int>>(X+1, vec<int>(Y+1, MAX)));
  rep(i,N+1) {
    dp[i][0][0] = 0;
  }
  rep(i,N) {
    int a = A[i].first, b = A[i].second;
    rep(j,X+1) {
      int x_ = min(j+a, X);
      rep(k,Y+1) {
        dp[i+1][j][k] = min(dp[i][j][k], dp[i+1][j][k]);
        int y_ = min(k+b, Y);
        dp[i+1][x_][y_] = min(dp[i+1][x_][y_], dp[i][j][k]+1);
      }
    }
  }
  if (dp[N][X][Y] == MAX)
    print(-1);
  else
    print(dp[N][X][Y]);
  return 0;
}
