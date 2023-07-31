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

const int INF = 1e9;
int H, W;
vector<int> dx = {-1,0,1,0}, dy = {0,-1,0,1};

pair<int,int> newPos(int x, int y, int id, int step=1) {
  return {x+step*dx[id], y+step*dy[id]};
}

bool isRange(int h, int w) {
  return h>=0 && h<H && w>=0 && w<W;
}

int main() {
  cin >> H >> W;
  vector<string> S(H);
  rep(i,H) {
    cin >> S[i];
  }
  queue<pair<int,int>> q;
  string snuke = "snuke";
  vector<vector<int>> dist(H, vector<int>(W, -1));
  if (S[0][0] == 's')
    q.push({0,0});
  dist[0][0] = 0;
  while (!q.empty()) {
    auto [x,y] = q.front();
    q.pop();
    int d = (dist[x][y]+1)%5;
    rep(i,4) {
      auto [nx,ny] = newPos(x,y,i);
      if (!isRange(nx,ny) || dist[nx][ny] != -1)
        continue;
      if (S[nx][ny] == snuke[d]) {
        dist[nx][ny] = d;
        q.push({nx,ny});
      }
    }
  }
  printyesno(dist[H-1][W-1] != -1);
  return 0;
}
