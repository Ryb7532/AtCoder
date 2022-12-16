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
  int N,M;
  cin >> N >> M;
  vector<int> E(N);
  rep(i,M) {
    int A,B;
    cin >> A >> B;
    A--; B--;
    E[A] |= 1<<B;
    E[B] |= 1<<A;
  }
  vector<int> dp(1<<N, N+5);
  dp[0] = 1;
  for (int i=1; i<1<<N; i++) {
    int l;
    rep(j,N) {
      if ((i & 1<<j) == (1<<j))
        l = j;
    }
    if (dp[i-(1<<l)] == 1 && (E[l] & i) == i-(1<<l))
      dp[i] = 1;
  }
  rep(i,1<<N) {
    for (int j=i; --j &= i; ) {
      dp[i] = min(dp[i], dp[j]+dp[i-j]);
    }
  }
  print(dp[(1<<N)-1]);
  return 0;
}
