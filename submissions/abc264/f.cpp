#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define rrep(i,n) for (int i=(int)(n)-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;

int main() {
  int H,W;
  cin >> H >> W;
  vector<int> R(H), C(W);
  rep(i,H) {
    cin >> R[i];
  }
  rep(j,W) {
    cin >> C[j];
  }
  vector<string> A(H);
  rep(i,H) {
    cin >> A[i];
  }
  const ll INF = 1e18;
  vvvl dp(H, vvl(W, vl(4, INF)));
  dp[0][0][0] = 0;
  dp[0][0][1] = R[0];
  dp[0][0][2] = C[0];
  dp[0][0][3] = R[0]+C[0];
  rep(i,H) {
    rep(j,W) {
      if (i < H-1) {
        rep(k,4) {
          ll v;
          if (A[i][j] == A[i+1][j])
            v = dp[i][j][k];
          else
            v = dp[i][j][(k&2)+1-(k&1)];
          if (k&1)
            v += R[i+1];
          dp[i+1][j][k] = min(dp[i+1][j][k], v);
        }
      }
      if (j < W-1) {
        rep(k,4) {
          ll v;
          if (A[i][j] == A[i][j+1])
            v = dp[i][j][k];
          else
            v = dp[i][j][2-(k&2)+(k&1)];
          if (k&2)
            v += C[j+1];
          dp[i][j+1][k] = min(dp[i][j+1][k], v);
        }
      }
    }
  }
  ll res = INF;
  rep(k,4)
    res = min(res, dp[H-1][W-1][k]);
  if (res == INF)
    res = -1;
  print(res);
  return 0;
}
