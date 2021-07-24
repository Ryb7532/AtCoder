#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N;
  string S,X;
  cin >> N >> S >> X;
  vec<int> Y(N);
  rep(i,N) {
    Y[i] = S[i]-'0';
  }
  vec<vec<int>> dp(N+1, vec<int>(7, 0));
  dp[N][0]++;
  for (int i=N-1; i>=0; i--) {
    if (X[i]=='T') {
      rep(j,7) {
        int mod = (10*j) % 7;
        if (dp[i+1][mod]>0)
          dp[i][j]++;
        mod += Y[i];
        mod %= 7;
        if (dp[i+1][mod])
          dp[i][j]++;
      }
    } else {
      rep(j,7) {
        bool flag = true;
        int mod = (10*j) % 7;
        if (dp[i+1][mod]==0)
          flag = false;
        mod += Y[i];
        mod %= 7;
        if (dp[i+1][mod]==0)
          flag = false;
        if (flag)
          dp[i][j]++;
      }
    }
  }
  if (dp[0][0])
    print("Takahashi");
  else
    print("Aoki");
  return 0;
}
