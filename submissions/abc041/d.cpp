#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  int N, M;
  cin >> N >> M;
  vector<int> edge[N];
  vector<int> indg(N,0);
  rep(i,M) {
    int x,y;
    cin >> x >> y;
    x--; y--;
    edge[x].push_back(y);
    indg[y]++;
  }
  int zrin = 0;
  repr(i,N,0) {
    zrin = zrin<<1;
    if (indg[i] == 0)
      zrin++;
  }
  vector<pair<ll,vector<int>>> dp(1 << 16);
  dp[0] = {1,indg};
  rep(n,N+1) {
    rep(i,1<<N) {
      if (dp[i].first == 0)
        continue;
      int bit = 0;
      rep(j,N) {
        if (i&(1<<j)) bit++;
      }
      if (bit != n) continue;
      queue<int> zero;
      rep(j,N) if (dp[i].second[j] == 0 && (i&(1<<j)) == 0) zero.push(j);
      while (!zero.empty()) {
        int z = zero.front();
        zero.pop();
        vector<int> tmp = dp[i].second;
        for (int e : edge[z]) {
          tmp[e]--;
        }
        dp[i+(1<<z)].first += dp[i].first;
        dp[i+(1<<z)].second = tmp;
      }
    }
  }
  print(dp[(1<<N)-1].first);
  return 0;
}
