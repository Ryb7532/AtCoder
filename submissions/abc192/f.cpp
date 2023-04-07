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
  int N;
  ll X;
  cin >> N >> X;
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  ll res = 1e18;
  rep(k,N) {
    int K = k+1;
    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(K+2, vector<ll>(K, -1)));
    dp[0][0][0] = 0;
    rep(i,N) {
      ll a = A[i];
      rep(j,K+1) {
        rep(l,K) {
          dp[i+1][j][l] = max(dp[i+1][j][l], dp[i][j][l]);
          if (dp[i][j][l] == -1)
            continue;
          dp[i+1][j+1][(l+a)%K] = max(dp[i+1][j+1][(l+a)%K], dp[i][j][l]+a);
        }
      }
    }
    ll c = dp[N][K][X%K];
    if (c == -1)
      continue;
    res = min(res, (X-c)/K);
  }
  print(res);
  return 0;
}
