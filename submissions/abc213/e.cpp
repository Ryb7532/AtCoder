#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"

#define P pair<int, pair<int,int>>
int H, W;
vec<string> S(500);
vec<vec<int>> d(500, vec<int>(500, -1));

vec<int> dh = {1, 0, -1, 0}, dw = {0, 1, 0, -1};

void bfs() {
  d[0][0] = 0;
  queue<P> q0, q1;
  q0.push({0, {0,0}});
  while(1) {
    while (!q0.empty()) {
      auto top = q0.front();
      int cost = top.first;
      auto hw = top.second;
      q0.pop();
      for (int i=0; i<4; i++) {
        int h = hw.first + dh[i];
        int w = hw.second + dw[i];
        if (h >=0 && h < H && w >= 0 && w < W && S[h][w] == '.' &&
            (d[h][w] == -1 || d[h][w] > cost)) {
          d[h][w] = cost;
          q0.push({cost, {h, w}});
        }
      }
      for (int dh_=-2; dh_<=2; dh_++) {
        int h = hw.first + dh_;
        for (int dw_=-2; dw_<=2; dw_++) {
          if (abs(dh_)+abs(dw_) == 4)
            continue;
          int w = hw.second + dw_;
          if (h >=0 && h < H && w >= 0 && w < W && d[h][w] == -1) {
            d[h][w] = cost + 1;
            q1.push({cost+1, {h, w}});
          }
        }
      }
    }
    while (!q1.empty()) {
      auto top = q1.front();
      q0.push(top);
      int cost = top.first;
      auto hw = top.second;
      q1.pop();
      for (int i=0; i<4; i++) {
        int h = hw.first + dh[i];
        int w = hw.second + dw[i];
        if (h >=0 && h < H && w >= 0 && w < W && S[h][w] == '.' &&
            d[h][w] == -1) {
          d[h][w] = cost;
          q0.push({cost, {h, w}});
        }
      }
    }
    if (q0.empty())
      break;
  }
}


int main() {
  cin >> H >> W;
  rep(i,H) {
    cin >> S[i];
  }
  bfs();
  print(d[H-1][W-1]);
  return 0;
}
