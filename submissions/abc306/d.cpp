#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl

const ll INF = -1e18;

int main() {
  int N;
  cin >> N;
  vector<int> X(N);
  vector<ll> Y(N);
  rep(i,N) {
    cin >> X[i] >> Y[i];
  }
  vector<vector<ll>> dp(N+1, vector<ll>(2, INF));
  dp[0][0] = 0;
  rep(i,N) {
    if (X[i]) {
      dp[i+1][0] = dp[i][0];
      dp[i+1][1] = max(dp[i][1], dp[i][0]+Y[i]);
    } else {
      dp[i+1][0] = max(dp[i][0]+max(0ll, Y[i]), dp[i][1]+Y[i]);
      dp[i+1][1] = dp[i][1];
    }
  }
  print(max(dp[N][0], dp[N][1]));
  return 0;
}
