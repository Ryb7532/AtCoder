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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  int H, W, K;
  scan(H, W, K);
  vector<string> S(H);
  rep(i,H) scan(S[i]);
  vector<vector<int>> seen(H, vector<int>(W, -1));
  int res = 0;
  vector<pair<pair<int,int>, int>> stack;
  rep(i,H) {
    rep(j,W) {
      if (S[i][j] == '#') continue;
      stack.push_back({{i,j}, 0});
      seen[i][j] = 0;
      while (!stack.empty()) {
        auto [p, d] = stack.back();
        auto [x, y] = p;
        if (d == K) {
          res++;
          stack.pop_back();
          seen[x][y] = -1;
          continue;
        }
        int k = seen[x][y];
        if (k == 4) {
          stack.pop_back();
          seen[x][y] = -1;
          continue;
        }
        seen[x][y]++;
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || nx >= H || ny < 0 || ny >= W || S[nx][ny] == '#' || seen[nx][ny] != -1) {
          continue;
        }
        stack.push_back({{nx, ny}, d + 1});
        seen[nx][ny] = 0;
      }
    }
  }
  print(res);
  return 0;
}