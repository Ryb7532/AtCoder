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

int main() {
  int H,W;
  ll K;
  cin >> H >> W >> K;
  int sx,sy;
  cin >> sx >> sy;
  sx--; sy--;
  vector<vector<ll>> A(H, vector<ll>(W));
  rep(i,H) {
    rep(j,W) {
      cin >> A[i][j];
    }
  }
  vector<vector<vector<ll>>> dp(H, vector<vector<ll>>(W, vector<ll>(H*W, -1e18)));
  dp[sx][sy][0] = 0;
  rep(k,H*W-1) {
    rep(x,H) {
      rep(y,W) {
        if (dp[x][y][k] < 0)
          continue;
        if (x > 0)
          chmax(dp[x-1][y][k+1], dp[x][y][k]+A[x-1][y]);
        if (x < H-1)
          chmax(dp[x+1][y][k+1], dp[x][y][k]+A[x+1][y]);
        if (y > 0)
          chmax(dp[x][y-1][k+1], dp[x][y][k]+A[x][y-1]);
        if (y < W-1)
          chmax(dp[x][y+1][k+1], dp[x][y][k]+A[x][y+1]);
      }
    }
  }
  ll res = 0;
  rep(x,H) {
    rep(y,W) {
      rep(k,H*W) {
        if (k > K)
          break;
        if (dp[x][y][k] < 0)
          continue;
        chmax(res, dp[x][y][k]+(K-k)*A[x][y]);
      }
    }
  }
  print(res);
  return 0;
}