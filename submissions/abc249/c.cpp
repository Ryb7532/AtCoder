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
  int N, K;
  cin >> N >> K;
  vector<vector<int>> alphabet(N, vector<int>(26, 0));
  rep(i,N) {
    string S;
    cin >> S;
    for (char c: S) {
      alphabet[i][c-'a']++;
    }
  }
  int res = 0;
  vector<vector<int>> dp(1<<N, vector<int>(26,0));
  for (int i=1; i<1<<N; i++) {
    int n = 0;
    while ((i & (1<<n)) == 0) n++;
    int cnt = 0;
    rep(j,26) {
      dp[i][j] = dp[i-(1<<n)][j] + alphabet[n][j];
      if (dp[i][j] == K) {
        cnt++;
      }
    }
    res = max(res, cnt);
  }
  print(res);
  return 0;
}
