#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(int)n; i++)
#define rrep(i,n) for (int i=(int)n-1; i>=0; i--)
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
  ll X,Y;
  cin >> N >> X >> Y;
  vector<ll> A(N), B(N);
  rep(i,N) {
    cin >> A[i];
  }
  rep(i,N) {
    cin >> B[i];
  }
  vector<ll> dp(1<<N, 2e18);
  dp[0] = 0;
  rep(i,(1<<N)-1) {
    int id = 0;
    rep(j,N) {
      if (i&(1<<j))
        id++;
    }
    int sw = 0;
    rep(j,N) {
      if (i&(1<<j))
        continue;
      dp[i+(1<<j)] = min(dp[i+(1<<j)], dp[i]+sw*Y+abs(A[j]-B[id])*X);
      sw++;
    }
  }
  print(dp[(1<<N)-1]);
  return 0;
}
