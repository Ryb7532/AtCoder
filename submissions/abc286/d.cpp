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
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int N,X;
  cin >> N >> X;
  vector<bool> dp(X+1, false);
  dp[0] = true;
  rep(i,N) {
    int A,B;
    cin >> A >> B;
    rep(j,X+1) {
      if (!dp[X-j])
        continue;
      rep(k,B) {
        if (X-j+A*(k+1) > X)
          break;
        dp[X-j+A*(k+1)] = true;
      }
    }
  }
  printyesno(dp[X]);
  return 0;
}
