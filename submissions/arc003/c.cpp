#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

int H, W;
vector<int> dx = {-1,0,1,0}, dy = {0,-1,0,1};
// vector<int> dx = {-1,-1,-1,0,1,1,1,0}, dy = {1,0,-1,-1,-1,0,1,1};

pair<int,int> newPos(int x, int y, int id, int step=1) {
  return {x+step*dx[id], y+step*dy[id]};
}

bool isRange(int h, int w) {
  return h>=0 && h<H && w>=0 && w<W;
}

int main() {
  cin >> H >> W;
  vector<string> C(H);
  int sx, sy, gx, gy;
  rep(i,H) {
    cin >> C[i];
    rep(j,W) {
      if (C[i][j] == 's') {
        sx = i; sy = j;
      }
      if (C[i][j] == 'g') {
        gx = i; gy = j;
      }
    }
  }
  vector<vector<ld>> B(10, vector<ld>(250005));
  rep(i,10) {
    B[i][0] = i;
    rep(j,H*W+5) {
      B[i][j+1] = B[i][j]*0.99;
    }
  }
  {
    vector<vector<bool>> reach(H, vector<bool>(W, false));
    queue<pair<int,int>> q;
    reach[sx][sy] = true;
    q.push({sx,sy});
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      rep(k,4) {
        auto [nx, ny] = newPos(x,y,k);
        if (isRange(nx,ny) && C[nx][ny] != '#') {
          if (reach[nx][ny])
            continue;
          reach[nx][ny] = true;
          q.push({nx,ny});
        }
      }
    }
    if (!reach[gx][gy]) {
      print(-1);
      return 0;
    }
  }
  const int INF = 1e9;
  ld l = 0.0, u = 10.0;
  while (u-l > 1e-10) {
    ld m = (u+l)/2;
    vector<vector<int>> T(H, vector<int>(W, INF));
    queue<pair<int,int>> q;
    q.push({sx, sy});
    T[sx][sy] = 0;
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      int t = T[x][y];
      rep(k,4) {
        auto [nx, ny] = newPos(x,y,k);
        if (isRange(nx,ny) && C[nx][ny] != '#') {
          if (nx == gx && ny == gy) {
            T[nx][ny] = 0;
            continue;
          }
          if (nx == sx && ny == sy)
            continue;
          if (B[C[nx][ny]-'0'][t+1] >= m) {
            if (T[nx][ny] == INF)
              q.push({nx,ny});
            T[nx][ny] = min(T[nx][ny], t+1);
          }
        }
      }
    }
    if (T[gx][gy] == 0)
      l = m;
    else
      u = m;
  }
  print(fix(10) << l);
  return 0;
}