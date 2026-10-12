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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
  int H,W,D;
  scan(H,W,D);
  vector<string> S(H);
  rep(i,H) scan(S[i]);
  vector<vector<int>> dis(H, vector<int>(W, 1e9));
  queue<pair<int,int>> queue;
  rep(i,H) {
    rep(j,W) {
      if (S[i][j] == 'H') {
        queue.push({i,j});
        dis[i][j] = 0;
      }
    }
  }
  while (!queue.empty()) {
    auto [x,y] = queue.front();
    queue.pop();
    int d = dis[x][y];
    rep(k,4) {
      int x1 = x + dx[k], y1 = y + dy[k];
      if (x1 < 0 || x1 >= H || y1 < 0 || y1 >= W) continue;
      if (S[x1][y1] != '.') continue;
      if (dis[x1][y1] == 1e9) queue.push({x1, y1});
      chmin(dis[x1][y1], d+1);
    }
  }
  int res = 0;
  rep(i,H) {
    rep(j,W) {
      if (dis[i][j] <= D) res++;
    }
  }
  print(res);
  return 0;
}