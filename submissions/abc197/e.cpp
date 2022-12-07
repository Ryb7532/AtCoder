#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"

#define INF 1e9+1

int main() {
  int N;
  cin >> N;
  vec<pair<ll,ll>> C(N+2, pair<int,int>(INF, -INF));
  C[0] = {0,0};
  C[N+1] = {0,0};
  ll x,c;
  rep(i,N) {
    cin >> x >> c;
    C[c].first = min(C[c].first, x);
    C[c].second = max(C[c].second, x);
  }
  vec<vec<ll>> dp(N+2, vec<ll>(2));
  dp[0][0] = 0;
  dp[0][1] = 0;
  rep(i,N+1) {
    if (C[i+1].first==INF) {
      dp[i+1][0] = dp[i][0];
      dp[i+1][1] = dp[i][1];
      C[i+1].first = C[i].first;
      C[i+1].second = C[i].second;
      continue;
    }
    ll fromL = abs(C[i].first-C[i+1].second)+abs(C[i].second-C[i].first);
    ll fromR = abs(C[i].second-C[i+1].second)+abs(C[i].second-C[i].first);
    dp[i+1][0] = min(dp[i][0]+fromL, dp[i][1]+fromR);
    fromL = abs(C[i].first-C[i+1].first)+abs(C[i].second-C[i].first);
    fromR = abs(C[i].second-C[i+1].first)+abs(C[i].second-C[i].first);
    dp[i+1][1] = min(dp[i][0]+fromL, dp[i][1]+fromR);
  }
  print(dp[N+1][0]);
  return 0;
}
