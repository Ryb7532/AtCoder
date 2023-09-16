#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl

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
  vector<string> A(H);
  rep(i,H) {
    cin >> A[i];
  }
  bool right = false;
  int sx,sy,gx,gy;
  rep(i,H) {
    rep(j,W) {
      int drct = -1;
      if (A[i][j] == '>')
        drct = 3;
      else if (A[i][j] == '<')
        drct = 1;
      else if (A[i][j] == 'v')
        drct = 2;
      else if (A[i][j] == '^')
        drct = 0;
      else if (A[i][j] == 'S') {
        sx = i; sy = j;
        A[i][j] = '.';
        continue;
      } else if (A[i][j] == 'G') {
        gx = i; gy = j;
        A[i][j] = '.';
        continue;
      } else
        continue;
      rep(k,1,2005) {
        auto [nx, ny] = newPos(i,j,drct,k);
        if (isRange(nx,ny) && (A[nx][ny] == '.' || A[nx][ny] == '-'))
          A[nx][ny] = '-';
        else
          break;
      }
    }
  }
  vector<vector<int>> dist(H, vector<int>(W, -1));
  queue<pair<int,int>> q;
  q.push({sx,sy});
  dist[sx][sy] = 0;
  while (!q.empty()) {
    auto [x,y] = q.front();
    q.pop();
    rep(i,4) {
      int nx = x + dx[i], ny = y + dy[i];
      if (isRange(nx,ny) && A[nx][ny] == '.' && dist[nx][ny] == -1) {
        q.push({nx,ny});
        dist[nx][ny] = dist[x][y]+1;
      }
    }
  }
  print(dist[gx][gy]);
  return 0;
}