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
  int N,S;
  cin >> N >> S;
  vector<int> A(N),B(N);
  rep(i,N) {
    cin >> A[i] >> B[i];
  }
  vector<vector<pair<bool,string>>> dp(N+1, vector<pair<bool,string>>(S+1, {false, ""}));
  dp[0][0] = {true, ""};
  rep(i,N) {
    int a = A[i], b = B[i];
    rep(j,S+1) {
      auto state = dp[i][j];
      if (state.first) {
        if (a+j <= S) {
          dp[i+1][a+j] = {true, state.second + "H"};
        }
        if (b+j <= S) {
          dp[i+1][b+j] = {true, state.second + "T"};
        }
      }
    }
  }
  if (dp[N][S].first) {
    print(Yes);
    print(dp[N][S].second);
  } else {
    print(No);
  }
  return 0;
}
