#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()
int R, C, sy, sx, gy, gx;
string c[50];
int d[50][50];


void init() {
  rep(i, R) {
    rep(j, C) {
      d[i][j] = -1;
    }
  }
}

void bfs() {
  init();
  queue<tuple<int, int, int>> q;
  q.push(make_tuple(sy, sx, 0));
  while (!q.empty()) {
    auto e = q.front();
    q.pop();
    int y = get<0>(e), x = get<1>(e), dis = get<2>(e);
    if (d[y][x] != -1)
      continue;
    d[y][x] = dis;
    if (c[y-1][x] == '.')
      q.push(make_tuple(y-1, x, dis+1));
    if (c[y+1][x] == '.')
      q.push(make_tuple(y+1, x, dis+1));
    if (c[y][x-1] == '.')
      q.push(make_tuple(y, x-1, dis+1));
    if (c[y][x+1] == '.')
      q.push(make_tuple(y, x+1, dis+1));
  }
  return;
}

int main() {
  cin >> R >> C >> sy >> sx >> gy >> gx;
  sy--; sx--; gy--; gx--;
  rep(i, R) {
    cin >> c[i];
  }
  bfs();
  print(d[gy][gx]);
  return 0;
}
