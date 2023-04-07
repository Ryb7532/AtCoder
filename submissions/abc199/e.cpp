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
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int N,M;
  cin >> N >> M;
  vector<vector<pair<int,int>>> A(N+1);
  rep(_,M) {
    int X,Y,Z;
    cin >> X >> Y >> Z;
    A[X].push_back({Y,Z});
  }
  vector<ll> dp(1<<N, 0);
  dp[0] = 1;
  rep(i,1<<N) {
    int cnt = 0;
    rep(j,N) {
      if (i&(1<<j))
        cnt++;
    }
    for (auto e: A[cnt]) {
      int z = 0;
      int y = e.first;
      rep(k,y) {
        if (i&(1<<k))
          z++;
      }
      if (z > e.second)
        dp[i] = 0;
    }
    rep(j,N) {
      if (i&(1<<j))
        continue;
      dp[i+(1<<j)] += dp[i];
    }
  }
  print(dp[(1<<N)-1]);
  return 0;
}
