#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int H,W;
  cin >> H >> W;
  vector<string> C(H);
  rep(i,H) {
    cin >> C[i];
  }
  vector<vector<int>> d(H, vector<int>(W,0));
  d[0][0] = 1;
  queue<pair<int,int>> q;
  q.push({0,0});
  while (!q.empty()) {
    auto top = q.front();
    q.pop();
    int h = top.first, w = top.second;
    if (h+1<H && C[h+1][w]=='.') {
      if (d[h+1][w]==0) {
        d[h+1][w] = d[h][w]+1;
        q.push({h+1,w});
      }
    }
    if (w+1<W && C[h][w+1]=='.') {
      if (d[h][w+1]==0) {
        d[h][w+1] = d[h][w]+1;
        q.push({h,w+1});
      }
    }
  }
  int res = 0;
  rep(i,H) {
    rep(j,W) {
      res = max(res, d[i][j]);
    }
  }
  print(res);
  return 0;
}
