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


const int INF = 1e5;

int main() {
  int H,W;
  cin >> H >> W;
  vector<string> S(H);
  vector<vector<int>> dp(H, vector<int>(W,INF));
  rep(i,H) {
    cin >> S[i];
  }
  queue<pair<int,int>> q;
  q.push({0,0});
  dp[0][0] = (S[0][0] == '#');
  while (!q.empty()) {
    auto top = q.front();
    q.pop();
    int x = top.first, y = top.second;
    if (x+1<H) {
      int inc = (S[x+1][y]=='#' && S[x+1][y]!=S[x][y]);
      if (dp[x+1][y] == INF)
        q.push({x+1,y});
      dp[x+1][y] = min(dp[x+1][y], dp[x][y]+inc);
    }
    if (y+1<W) {
      int inc = (S[x][y+1]=='#' && S[x][y+1]!=S[x][y]);
      if (dp[x][y+1] == INF)
        q.push({x,y+1});
      dp[x][y+1] = min(dp[x][y+1], dp[x][y]+inc);
    }
  }
  print(dp[H-1][W-1]);
  return 0;
}
