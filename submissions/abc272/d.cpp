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
  vector<int> S(M+1, -1);
  vector<pair<int,int>> E;
  for (ll i=0; i*i<=M; i++) {
    S[i*i] = i;
  }
  rep(i,M+1) {
    if (S[i] != -1 && S[M-i] != -1)
      E.push_back({S[i], S[M-i]});
  }
  const int maxC = 1e9;
  vector<vector<int>> dp(N, vector<int>(N, maxC));
  dp[0][0] = 0;
  vector<int> dx = {1,1,-1,-1}, dy={1,-1,1,-1};
  queue<pair<int,int>> q;
  q.push({0,0});
  while (!q.empty()) {
    int x,y;
    auto top = q.front();
    q.pop();
    x = top.first;
    y = top.second;
    int c = dp[x][y];
    for (auto e: E) {
      rep(j,4) {
        int nx = x + dx[j] * e.first, ny = y + dy[j] * e.second;
        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
          continue;
        if (dp[nx][ny] == maxC)
          q.push({nx,ny});
        dp[nx][ny] = min(dp[nx][ny], c+1);
      }
    }
  }
  rep(i,N) {
    rep(j,N) {
      cout << (dp[i][j] == maxC ? -1 : dp[i][j]) << " ";
    }
    cout << endl;
  }
  return 0;
}
