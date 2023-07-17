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


int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  rep(i,N) {
    cin >> S[i];
  }
  vector<vector<int>> dp(1<<N, vector<int>(N, -1));
  for (int i=(1<<N)-1; i>0; i--) {
    int turn = 0;
    rep(j,N) {
      if (i&(1<<j))
        turn++;
    }
    rep(j,N) {
      if ((i&(1<<j)) == 0)
        continue;
      bool f = false;
      rep(k,N) {
        if (i&(1<<k))
          continue;
        if (S[j].back() != S[k].front())
          continue;
        if (dp[i+(1<<k)][k]%2 == turn%2 || dp[i+(1<<k)][k] == -1)
          f = true;
      }
      if (f)
        dp[i][j] = turn%2;
      else
        dp[i][j] = 1-turn%2;
    }
  }
  bool flag = false;
  rep(i,N) {
    if (dp[1<<i][i] == 0 || dp[1<<i][i] == -1)
      flag = true;
  }
  print((flag ? "First" : "Second"));
  return 0;
}
