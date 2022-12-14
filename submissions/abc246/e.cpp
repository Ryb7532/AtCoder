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


vector<int> dx = {1, 1, -1, -1}, dy = {1, -1, 1, -1};

int main() {
  int N;
  cin >> N;
  int Ax,Ay,Bx,By;
  cin >> Ax >> Ay >> Bx >> By;
  Ax--; Ay--; Bx--; By--;
  vector<string> S(N);
  rep(i,N) {
    cin >> S[i];
  }
  vector<vector<int>> dist(N, vector<int>(N,-1));
  queue<pair<int,int>> q;
  dist[Ax][Ay] = 0;
  q.push({Ax, Ay});
  while (!q.empty()) {
    auto top = q.front();
    int x = top.first, y = top.second;
    int c = dist[x][y];
    q.pop();
    rep(j,4) {
      int nx = x, ny = y;
      rep(i,N) {
        nx += dx[j];
        ny += dy[j];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || S[nx][ny] == '#') {
          break;
        }
        if (dist[nx][ny] == -1) {
          q.push({nx,ny});
          dist[nx][ny] = c+1;
        }
        if (dist[nx][ny] < c+1) {
          break;
        }
      }
    }
  }
  print(dist[Bx][By]);
  return 0;
}
