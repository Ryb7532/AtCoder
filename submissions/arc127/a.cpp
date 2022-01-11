#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
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
  string S;
  cin >> S;
  int N = S.size();
  ll res = 0;
  vector<ll> dp(N+1);
  dp[N] = 0;
  for (int i=N-1; i>0; i--) {
    dp[i] = dp[i+1]*10+1;
    res += dp[i];
  }
  dp[0] = dp[1]*10+1;
  rep(i,N) {
    if (S[i]-'0'>1) {
      res += dp[i];
      break;
    }
    if (S[i]-'0'<1) {
      break;
    }
    ll cnt = 0;
    for (int j=i+1; j<N; j++) {
      cnt *= 10;
      cnt += S[j]-'0';
    }
    res += cnt+1;
  }
  print(res);
  return 0;
}
