#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << a << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
typedef struct {
  int x; int y;
} point;

const int INF = 1e9;
int H, W;
string C[500];
vec<vec<int>> cost(500,vec<int>(500,INF));

void bfs(point s) {
  queue<pair<point,int>> q;
  q.push(make_pair(s,0));
  while (!q.empty()) {
    auto top = q.front();
    q.pop();
    int x,y,c;
    x = top.first.x; y = top.first.y;
    c = top.second;
    if (cost[x][y] <= c)
      continue;
    cost[x][y] = c;
    if (x>0) {
      if (C[x-1][y] != '#')
        q.push({{x-1,y},c});
      else if (c<2)
        q.push({{x-1,y},c+1});
    }
    if (x<H-1) {
      if (C[x+1][y] != '#')
        q.push({{x+1,y},c});
      else if (c<2)
        q.push({{x+1,y},c+1});
    }
    if (y>0) {
      if (C[x][y-1] != '#')
        q.push({{x,y-1},c});
      else if (c<2)
        q.push({{x,y-1},c+1});
    }
    if (y<W-1) {
      if (C[x][y+1] != '#')
        q.push({{x,y+1},c});
      else if (c<2)
        q.push({{x,y+1},c+1});
    }
  }
}


int main() {
  cin >> H >> W;
  rep(i,H) cin >> C[i];
  point s,g;
  rep(i,H) {
    rep(j,W) {
      if (C[i][j] == 's') {
        s = {i,j};
      }
      if (C[i][j] == 'g') {
        g = {i,j};
      }
    }
  }
  bfs(s);
  print(((cost[g.x][g.y]<=2)?"YES":"NO"));
  return 0;
}
