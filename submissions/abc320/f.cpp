#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl

int main() {
  int N,H;
  cin >> N >> H;
  vector<int> X(N+1), P(N+1), F(N+1);
  rep(i,1,N+1) {
    cin >> X[i];
  }
  X[0] = 0;
  rep(i,1,N) {
    cin >> P[i] >> F[i];
  }
  P[N] = F[N] = 0;
  const int INF = 1e9;
  vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(H+1, vector<int>(H+1, INF)));
  rep(k,H+1) {
    dp[0][H][k] = 0;
  }
  rep(i,1,N+1) {
    int d = X[i] - X[i-1];
    rep(j,d,H+1) {
      rep(k,H+1-d) {
        dp[i][j-d][k+d] = min(dp[i][j-d][k+d], dp[i-1][j][k]);
        dp[i][min(H,j-d+F[i])][k+d] = min(dp[i][min(H,j-d+F[i])][k+d], dp[i-1][j][k]+P[i]);
        if (k+d-F[i] >= 0)
          dp[i][j-d][k+d-F[i]] = min(dp[i][j-d][k+d-F[i]], dp[i-1][j][k]+P[i]);
      }
      rep(k,F[i]+1)
        dp[i][j-d][H-k] = min(dp[i][j-d][H-k], dp[i-1][j][H-d]+P[i]);
    }
  }
  int res = INF;
  rep(j,H+1) {
    res = min(res, dp[N][j][j]);
  }
  if (res == INF)
    res = -1;
  print(res);
  return 0;
}