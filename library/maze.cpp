#include <bits/stdc++.h>
using namespace std;
#define vec vector


typedef struct{
  int x;
  int y;
} point;
const int INF = 1e9, M_size = 1000;

int H,W;
string C[M_size];
vec<vec<int>> cost(M_size,vec<int>(M_size,INF));

void bfs(point s) {
  queue<pair<point,int>> q;
  q.push({s,0});
  while (!q.empty()) {
    auto top = q.front();
    q.pop();
    int x,y,c;
    x = top.first.x; y = top.first.y;
    c = top.second;
    if (cost[x][y]<=c)
      continue;
    cost[x][y] = c;
    if (x>0 && C[x-1][y] != '#') {
      q.push({{x-1,y},c+1});
    }
    if (x<H-1 && C[x+1][y] != '#') {
      q.push({{x+1,y},c+1});
    }
    if (y>0 && C[x][y-1] != '#') {
      q.push({{x,y-1},c+1});
    }
    if (y<W-1 && C[x][y+1] != '#') {
      q.push({{x,y+1},c+1});
    }
  }
}
