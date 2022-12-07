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

#define pii pair<int,int>

int H,W;
vec<string> a(2000);
vec<vec<int>> t(2000, vec<int>(2000, -1));
map<char, vec<pii>> m;
map<char, bool> check;
queue<pair<pii,int>> q;

int bfs() {
  while (!q.empty()) {
    auto f = q.front();
    q.pop();
    pii p = f.first;
    int x = p.first;
    int y = p.second;
    int cost = f.second;
    if (a[x][y] != '.' && !check[a[x][y]]) {
      for (auto &e : m[a[x][y]]) {
        if (e == p)
          continue;
        if (t[e.first][e.second] == -1) {
          t[e.first][e.second] = cost+1;
          q.push({e,cost+1});
        }
      }
      check[a[x][y]] = true;
    }
    if (x>0 && a[x-1][y] != '#' && t[x-1][y] == -1) {
      t[x-1][y] = cost+1;
      q.push({{x-1,y},cost+1});
    }
    if (x<H-1 && a[x+1][y] != '#' && t[x+1][y] == -1) {
      t[x+1][y] = cost+1;
      q.push({{x+1,y},cost+1});
    }
    if (y>0 && a[x][y-1] != '#' && t[x][y-1] == -1) {
      t[x][y-1] = cost+1;
      q.push({{x,y-1},cost+1});
    }
    if (y<W-1 && a[x][y+1] != '#' && t[x][y+1] == -1) {
      t[x][y+1] = cost+1;
      q.push({{x,y+1},cost+1});
    }
  }
  pii S = m['S'].front();
  int res = t[S.first][S.second];
  return res;
}

int main() {
  cin >> H >> W;
  rep(i,H)
    cin >> a[i];
  rep(i,H) {
    rep(j,W) {
      if (a[i][j] == '#' || a[i][j] == '.')
        continue;
      m[a[i][j]].push_back({i,j});
    }
  }
  pii G = m['G'].front();
  t[G.first][G.second]=0;
  q.push({G,0});
  print(bfs());
  return 0;
}
