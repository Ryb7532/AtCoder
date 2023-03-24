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


using Grid = struct{int h; int w; int p;};
vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

int main() {
  int H,W;
  cin >> H >> W;
  vector<string> C(H);
  rep(i,H) {
    cin >> C[i];
  }
  int X,Y;
  rep(i,H) {
    rep(j,W) {
      if (C[i][j] == 'S') {
        Y = i;
        X = j;
      }
    }
  }
  vector<vector<vector<bool>>> seen(H, vector<vector<bool>>(W, vector<bool>(4, false)));
  queue<Grid> q;
  rep(i,4) {
    int y = Y + dy[i];
    int x = X + dx[i];
    if (y < 0 || y >= H || x < 0 || x >= W)
      continue;
    if (C[y][x] == '.') {
      seen[y][x][i] = true;
      q.push({y, x, i});
    }
  }
  bool flag = false;
  while (!q.empty()) {
    Grid top = q.front();
    q.pop();
    int h,w,p;
    h = top.h;
    w = top.w;
    p = top.p;
    bool f = false;
    rep(i,4) {
      if (i==p)
        continue;
      if (seen[h][w][i])
        f = true;
    }
    if (f) {
      flag = true;
      break;
    }
    rep(i,4) {
      int y = h + dy[i];
      int x = w + dx[i];
      if (y < 0 || y >= H || x < 0 || x >= W)
        continue;
      if (C[y][x] != '.')
        continue;
      if (seen[y][x][p])
        continue;
      seen[y][x][p] = true;
      q.push({y,x,p});
    }
  }
  print((flag ? Yes : No));
  return 0;
}
