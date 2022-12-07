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


int main() {
  int H,W,N;
  cin >> H >> W >> N;
  int sx,sy,gx,gy;
  cin >> sx >> sy >> gx >> gy;
  sx--; sy--;
  gx--; gy--;
  map<int,set<int>> ObjectX, ObjectY;
  rep(i,N) {
    int x,y;
    cin >> x >> y;
    x--; y--;
    ObjectX[x].insert(y);
    ObjectY[y].insert(x);
  }
  queue<pair<int,int>> q;
  map<pair<int,int>,int> cost;
  q.push(make_pair(sx,sy));
  cost[make_pair(sx,sy)] = 0;
  while (!q.empty()) {
    auto top = q.front();
    int x = top.first, y = top.second;
    q.pop();
    if (x < 0 || x >= H || y < 0 || y >= W)
      continue;
    int c = cost[make_pair(x, y)];
    auto OX = ObjectX[x];
    auto OY = ObjectY[y];
    auto it0 = OX.lower_bound(y);
    auto it1 = OY.lower_bound(x);
    if (it0 != OX.end()) {
      int y_ = (*it0) - 1;
      if (cost.find(make_pair(x,y_)) == cost.end()) {
        cost[make_pair(x,y_)] = c+1;
        q.push(make_pair(x,y_));
      }
    }
    if (it0 != OX.begin()) {
      it0--;
      int y_ = (*it0) + 1;
      if (cost.find(make_pair(x,y_)) == cost.end()) {
        cost[make_pair(x,y_)] = c+1;
        q.push(make_pair(x,y_));
      }
    }
    if (it1 != OY.end()) {
      int x_ = (*it1) - 1;
      if (cost.find(make_pair(x_,y)) == cost.end()) {
        cost[make_pair(x_,y)] = c+1;
        q.push(make_pair(x_,y));
      }
    }
    if (it1 != OY.begin()) {
      it1--;
      int x_ = (*it1) + 1;
      if (cost.find(make_pair(x_,y)) == cost.end()) {
        cost[make_pair(x_,y)] = c+1;
        q.push(make_pair(x_,y));
      }
    }
  }
  if (cost.find(make_pair(gx,gy)) == cost.end()) {
    print(-1);
  } else {
    int res = cost[make_pair(gx,gy)];
    print(res);
  }
  return 0;
}
