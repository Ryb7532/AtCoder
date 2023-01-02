#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N;
  cin >> N;
  vector<ll> X(N), Y(N), P(N);
  rep(i,N) {
    cin >> X[i] >> Y[i] >> P[i];
  }
  vector<vector<ll>> C(N, vector<ll>(N));
  const ll M = 2e18+5;
  rep(i,N) {
    rep(j,N) {
      if (i == j)
        C[i][j] = 0;
      C[i][j] = (abs(X[j]-X[i]) + abs(Y[j]-Y[i]) + P[i] - 1) / P[i];
    }
  }
  ll res = M;
  rep(i,N) {
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
    q.push({0,i});
    vector<ll> dist(N, M);
    dist[i] = 0;
    while (!q.empty()) {
      ll c = q.top().first;
      int n = q.top().second;
      q.pop();
      if (c > dist[n])
        continue;
      rep(j,N) {
        if (n == j)
          continue;
        ll nc = max(c, C[n][j]);
        if (dist[j] > nc) {
          q.push({nc, j});
          dist[j] = nc;
        }
      }
    }
    ll cost = 0;
    rep(j,N) {
      cost = max(cost, dist[j]);
    }
    res = min(res, cost);
  }
  print(res);
  return 0;
}
