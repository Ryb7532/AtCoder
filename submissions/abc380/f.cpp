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

int T;
vector<int> C(12), P(13);
vector<vector<int>> dp(2, vector<int>(531441, -1));

int dfs(int player, int state) {
  // print(player, state);
  if (dp[player][state] != -1) return dp[player][state];
  int res = 1-player, tmp;
  rep(i,T) {
    int si = state / P[i] % 3;
    if (si != player) continue;
    rep(j,T) {
      if (C[i] <= C[j]) continue;
      int sj = state / P[j] % 3;
      if (sj != 2) continue;
      tmp = dfs(1-player, state+(2-player)*P[i]+(player-2)*P[j]);
      if (tmp == player) res = player;
    }
    tmp = dfs(1-player, state+(2-si)*P[i]);
    if (tmp == player) res = player;
  }
  // print(player, state, res);
  return dp[player][state] = res;
}


int main() {
  int N,M,L;
  scan(N, M, L);
  T = N+M+L;
  int state = 0;
  P[0] = 1;
  rep(i,T) {
    scan(C[i]);
    P[i+1] = P[i]*3;
  }
  rep(_,L) state *= 3, state += 2;
  rep(_,M) state *= 3, state += 1;
  rep(_,N) state *= 3;
  int res = dfs(0, state);
  print((res == 0 ? "Takahashi" : "Aoki"));
  return 0;
}