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


int main() {
  int N,M;
  cin >> N >> M;
  vec<ll> A(N);
  vec<vec<ll>> R(N);
  vec<vec<ll>> dp(N, vec<ll>(2,-1e10));
  rep(i,N)
    cin >> A[i];
  rep(_,M) {
    ll X,Y;
    cin >> X >> Y;
    X--; Y--;
    R[Y].push_back(X);
  }
  for (int i=N-1; i>=0; i--) {
    dp[i][0] = dp[i][1] - A[i];
    dp[i][1] = max(dp[i][1],A[i]);
    for (auto &e: R[i]) {
      dp[e][1] = max(dp[e][1], dp[i][1]);
    }
  }
  ll res = -1e10;
  rep(i,N) {
    res = max(res,dp[i][0]);
  }
  print(res);
  return 0;
}
