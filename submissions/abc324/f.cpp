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

int main() {
  int N,M;
  cin >> N >> M;
  vector<vector<int>> from(M);
  vector<int> to(M), B(M), C(M);
  rep(i,M) {
    int u,v;
    cin >> u >> v >> B[i] >> C[i];
    u--; v--;
    to[i] = v;
    from[u].push_back(i);
  }
  ld lv = 0.0, uv = 1e18;
  while (uv-lv > 1e-9) {
    ld m = (lv+uv)/2;
    vector<ld> dp(N, -1e18);
    dp[0] = 0;
    rep(i,N) {
      for (auto id: from[i]) {
        int v = to[id];
        dp[v] = max(dp[v], dp[i]+B[id]-m*C[id]);
      }
    }
    if (dp[N-1]>=0)
      lv = m;
    else
      uv = m;
  }
  print(fix(10) << lv);
  return 0;
}