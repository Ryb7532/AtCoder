#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define rrep(i,n) for (int i=(int)(n)-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int N;
vector<int> D;
vector<vector<pair<int,ll>>> Edge;
vector<pair<ll,ll>> dp;

void dfs(int n, int p) {
  ll res = 0;
  multiset<ll, greater<ll>> diff;
  for (auto [d,w]: Edge[n]) {
    if (d == p)
      continue;
    dfs(d, n);
    ll a = dp[d].second;
    ll b = dp[d].first + w;
    res += a;
    diff.insert(b-a);
  }
  int d = 0;
  dp[n] = {res, res};
  if (D[n] == 0)
    dp[n].first = -1e18;
  for (ll e: diff) {
    if (e <= 0 || d >= D[n])
      break;
    if (d < D[n]-1)
      dp[n].first += e;
    dp[n].second += e;
    d++;
  }
}

int main() {
  cin >> N;
  D.resize(N);
  Edge.resize(N);
  dp.resize(N);
  rep(i,N) {
    cin >> D[i];
  }
  rep(i,N-1) {
    int u,v;
    ll w;
    cin >> u >> v >> w;
    u--; v--;
    Edge[u].push_back({v, w});
    Edge[v].push_back({u, w});
  }
  dfs(0,-1);
  print(dp[0].second);
  return 0;
}
