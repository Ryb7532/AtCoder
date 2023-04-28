#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,s,e) for (int i=s; i<(int)(e); i++)
#define repn(i,n) rep(i,0,n)
#define rrep(i,s,e) for (int i=s-1; i>=e; i--)
#define rrepn(i,n) rrep(i,n,0)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int N,M;
  cin >> N >> M;
  vector<vector<pair<int,ll>>> Edge(N);
  repn(_,M) {
    int u,v;
    ll s;
    cin >> u >> v >> s;
    u--; v--;
    Edge[u].push_back({v,s});
    Edge[v].push_back({u,s});
  }
  const ll INF = 1e18;
  bool flag = true;
  vector<vector<ll>> dp(N, vector<ll>(2,INF));
  dp[0][0] = 0;
  queue<pair<int,int>> q;
  q.push({0,0});
  while (flag && !q.empty()) {
    auto [n,f] = q.front();
    q.pop();
    ll vn = dp[n][f];
    for (auto [d,v]: Edge[n]) {
      if (dp[d][1-f] == INF) {
        dp[d][1-f] = v-vn;
        q.push({d,1-f});
      } else if (dp[d][1-f] != v-vn) {
        flag = false;
      }
    }
  }
  ll l = 1, r = INF;
  if (!flag) {
    r = 1, l = INF;
  }
  repn(i,N) {
    l = max(l, -dp[i][0]+1);
    r = min(r, dp[i][1]-1);
    if (dp[i][0] != INF && dp[i][1] != INF) {
      ll sum = dp[i][1] - dp[i][0];
      if (sum%2)
        l = INF, r = 1;
      l = max(l, sum/2), r = min(r, sum/2);
    }
  }
  print(max((ll)0,r-l+1));
  return 0;
}
