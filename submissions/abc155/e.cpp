#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int n = S.size();
  int dp[n+1][2];
  dp[0][0] = 0;
  dp[0][1] = 1;
  for (int i=0; i<n; i++) {
    dp[i+1][0] = min(dp[i][0]+(S[i]-'0'), dp[i][1]+10-(S[i]-'0'));
    dp[i+1][1] = min(dp[i][0]+(S[i]-'0')+1, dp[i][1]+9-(S[i]-'0'));
  }
  cout << dp[n][0] << endl;
  return 0;
}
