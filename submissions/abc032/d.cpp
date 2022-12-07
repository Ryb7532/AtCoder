#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()

const ll INF = 2e9;

int main() {
  int N, W;
  cin >> N >> W;
  ll v[N], w[N], vmax = 0, wmax = 0;
  rep(i, N) {
    cin >> v[i] >> w[i];
    vmax = max(vmax, v[i]);
    wmax = max(wmax, w[i]);
  }
  if (wmax <= 1000) {
    int M = wmax*N+1;
    ll dp[N+1][M];
    fill(dp[0], dp[0]+M, 0);
    rep(i, N) {
      rep(j, M) {
        dp[i+1][j] = dp[i][j];
        if (j >= w[i]) {
          dp[i+1][j] = max(dp[i+1][j], dp[i][j-w[i]]+v[i]);
        }
      }
    }
    ll ans = 0;
    rep(i, min(M, W+1)) {
      ans = max(ans, dp[N][i]);
    }
    print(ans);
  } else if (vmax <= 1000) {
    int M = vmax*N+1;
    ll dp[N+1][M];
    rep(i, N+1) {
      rep(j, M) {
        dp[i][j] = INF;
      }
    }
    dp[0][0] = 0;
    rep(i, N) {
      rep(j, M) {
        dp[i+1][j] = dp[i][j];
        if (j >= v[i]) {
          dp[i+1][j] = min(dp[i+1][j], dp[i][j-v[i]]+w[i]);
        }
      }
    }
    int ans = 0;
    rep(i, M) {
      if (dp[N][i] <= W)
        ans = max(ans, i);
    }
    print(ans);
  } else {
    int H = N/2;
    vector<pair<ll, ll>> l, r;
    rep(i, (1<<H)) {
      ll weight = 0, value = 0;
      rep(j, H) {
        if (((1<<j)&i) != 0) {
          weight += w[j];
          value += v[j];
        }
      }
      if (weight <= W)
        l.push_back(make_pair(weight, value));
    }
    rep(i, (1<<(N-H))) {
      ll weight = 0, value = 0;
      rep(j, N-H) {
        if (((1<<j)&i) != 0) {
          weight += w[j+H];
          value += v[j+H];
        }
      }
      if (weight <= W)
        r.push_back(make_pair(weight, value));
    }
    sort(all(l));
    sort(all(r));
    reverse(all(l));
    int ls = l.size(), rs = r.size(), id = 0;
    ll ans = 0, mv = 0;
    rep(i, ls) {
      while (id < rs && r[id].first+l[i].first <= W) {
        mv = max(mv, r[id].second);
        id++;
      }
      ans = max(ans, mv+l[i].second);
    }
    print(ans);
  }
  return 0;
}
