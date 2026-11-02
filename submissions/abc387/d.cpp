#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep1(n) rep2(_,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define printyn(f) cout << ((f) ? "Yes" : "No") << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}
void print() {cout << endl;}
template<typename Arg, typename... Args> void print(const Arg a, const Args... b) {
  cout << a;
  (cout << ... << (cout << ' ', b)) << endl;
}
template<class... T> void scan(T&... a) {(cin >> ... >> a);}

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
struct pos {
  int x;
  int y;
  int dir;
  pos(int x, int y, int dir) : x(x), y(y), dir(dir) {}
};

int main() {
  int H,W;
  scan(H,W);
  vector<string> S(H);
  rep(i,H) scan(S[i]);
  const int MAX = 1e9;
  vector<vector<vector<int>>> D(2, vector<vector<int>>(H, vector<int>(W, MAX)));
  queue<pos> Q;
  rep(i,H) rep(j,W) {
    if (S[i][j] != 'S') continue;
    D[0][i][j] = 0;
    Q.push(pos(i,j,0));
    D[1][i][j] = 0;
    Q.push(pos(i,j,1));
  }
  while (!Q.empty()) {
    auto p = Q.front();
    Q.pop();
    int x = p.x, y = p.y, dir = p.dir;
    int d = D[dir][x][y];
    rep(i,4) {
      if (i%2 != dir) continue;
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
      if (S[nx][ny] == '#' || D[1-dir][nx][ny] < MAX) continue;
      D[1-dir][nx][ny] = d+1;
      Q.push(pos(nx,ny,1-dir));
    }
  }
  int res = MAX;
  rep(i,H) rep(j,W) {
    if (S[i][j] != 'G') continue;
    chmin(res, D[0][i][j]);
    chmin(res, D[1][i][j]);
  }
  print((res < MAX ? res : -1));
  return 0;
}