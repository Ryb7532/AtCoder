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

int H, W;
vector<int> dh = {-1,0,1,0}, dw = {0,-1,0,1};

bool isRange(int h, int w) {
  return h>=0 && h<H && w>=0 && w<W;
}

int main() {
  cin >> H >> W;
  vector<string> A(H);
  rep(i,H) {
    cin >> A[i];
  }
  vector<vector<int>> dis(H, vector<int>(W,-1));
  queue<pair<int,int>> q;
  rep(i,H) {
    rep(j,W) {
      if (A[i][j] == '#') {
        q.push({i,j});
        dis[i][j] = 0;
      }
    }
  }
  while (!q.empty()) {
    auto top = q.front();
    q.pop();
    int h = top.first, w = top.second;
    int d = dis[h][w];
    rep(i,4) {
      if (isRange(h+dh[i], w+dw[i]) && dis[h+dh[i]][w+dw[i]]<0) {
        dis[h+dh[i]][w+dw[i]] = d+1;
        q.push({h+dh[i], w+dw[i]});
      }
    }
  }
  int res = 0;
  rep(i,H) {
    rep(j,W) {
      res = max(res, dis[i][j]);
    }
  }
  print(res);
  return 0;
}
