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


const int M = 1e9;

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<int>> A(H, vector<int>(W));
  rep(i,H) {
    rep(j,W) {
      cin >> A[i][j];
    }
  }
  vector<vector<int>> dp(H, vector<int>(1<<3, M));
  int res = M;
  rep(j,1<<3) {
    bool f = true;
    int a0,a1,a2;
    a0 = (j & (1<<2)) ? 1 : 0;
    a1 = (j & (1<<1)) ? 1 : 0;
    a2 = (j & (1<<0)) ? 1 : 0;
    rep(w, W) {
      bool exist = false;
      if ((A[0][w]+a1) % 2 == (A[1][w]+a2) % 2)
        exist = true;
      if (w > 0 && A[0][w] == A[0][w-1])
        exist = true;
      if (w < W-1 && A[0][w] == A[0][w+1])
        exist = true;
      if (!exist)
        f = false;
    }
    if (!f)
      continue;
    int cnt = 0;
    rep(k,3) {
      if (j&(1<<k))
        cnt++;
    }
    dp[0][j] = cnt;
  }
  rep(i,H-1) {
    rep(j,1<<3) {
      bool f = true;
      int a0,a1,a2;
      a0 = (j & (1<<2)) ? 1 : 0;
      a1 = (j & (1<<1)) ? 1 : 0;
      a2 = (j & (1<<0)) ? 1 : 0;
      rep(w, W) {
        bool exist = false;
        if (i < H-2 && (A[i+1][w]+a1) % 2 == (A[i+2][w]+a2) % 2)
          exist = true;
        if ((A[i+1][w]+a1) % 2 == (A[i][w]+a0) % 2)
          exist = true;
        if (w > 0 && A[i+1][w] == A[i+1][w-1])
          exist = true;
        if (w < W-1 && A[i+1][w] == A[i+1][w+1])
          exist = true;
        if (!exist)
          f = false;
      }
      if (!f)
        continue;
      int cnt = j&1;
      dp[i+1][j] = min(dp[i+1][j], min(dp[i][j>>1], dp[i][(1<<2)+(j>>1)]) + cnt);
    }
  }
  rep(j,1<<3) {
    res = min(res, dp[H-1][j]);
  }
  if (res == M)
    res = -1;
  print(res);
  return 0;
}
