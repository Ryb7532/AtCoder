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


vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};


int main() {
  int H,W,K;
  cin >> H >> W >> K;
  int x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;
  x1--; y1--;
  x2--; y2--;
  vector<string> S(H);
  rep(i,H) {
    cin >> S[i];
  }
  queue<pair<int,int>> q;
  vector<vector<int>> cost(H, vector<int>(W, -1));
  cost[x1][y1] = 0;
  q.push({x1,y1});
  while (!q.empty()) {
    auto top = q.front();
    q.pop();
    int x = top.first, y = top.second;
    int c = cost[x][y];
    rep(j,4) {
      for (int i=1; i<=K; i++) {
        int dx_ = i*dx[j];
        int dy_ = i*dy[j];
        if (x+dx_>=H || x+dx_<0 || y+dy_>=W || y+dy_<0)
          break;
        if (S[x+dx_][y+dy_]=='@')
          break;
        if (cost[x+dx_][y+dy_] == -1) {
          cost[x+dx_][y+dy_] = c+1;
          q.push({x+dx_, y+dy_});
        } else if (cost[x+dx_][y+dy_] >= c+1) {
          cost[x+dx_][y+dy_] = c+1;
        } else {
          break;
        }
      }
    }
  }
  print(cost[x2][y2]);
  return 0;
}
