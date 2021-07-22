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

const ll INF = 1e9;


int main() {
  int N,M,K;
  cin >> N >> M;
  vec<vec<int>> E(N);
  rep(_,M) {
    int A,B;
    cin >> A >> B;
    A--; B--;
    E[A].push_back(B);
    E[B].push_back(A);
  }
  cin >> K;
  vec<int> C(K);
  rep(i,K) {
    cin >> C[i];
    C[i]--;
  }
  vec<vec<ll>> dp(1<<K,vec<ll>(K,INF));
  rep(i,K) {
    vec<ll> cost(N,INF);
    queue<pair<int,ll>> Q;
    cost[C[i]] = 0;
    Q.push({C[i],0});
    while (!Q.empty()) {
      auto front = Q.front();
      Q.pop();
      ll c = front.second;
      c++;
      for (auto &e: E[front.first]) {
        if (cost[e]!=INF)
          continue;
        cost[e] = c;
        Q.push({e,c});
      }
    }
    rep(j,K) {
      dp[1<<i][j] = cost[C[j]];
    }
  }
  for(int i=1; i<(1<<K); i++) {
    rep(j,K) {
      rep(k,K) {
        if ((i&(1<<k)) == 0)
          continue;
        dp[i][k] = min(dp[i][k],dp[i-(1<<k)][j]+dp[1<<k][j]);
      }
    }
  }
  ll res = INF;
  rep(i,K) {
    res = min(res, dp[(1<<K)-1][i]);
  }
  if (res>=INF)
    res = -2;
  print(res+1);
  return 0;
}
