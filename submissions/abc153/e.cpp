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
  int H,N;
  cin >> H >> N;
  vector<pair<int,int>> M(N);
  rep(i,N) {
    int A,B;
    cin >> A >> B;
    M[i] = {A,B};
  }
  vector<int> dp(H+1,1e9);
  dp[0] = 0;
  rep(i,N) {
    int A,B;
    A = M[i].first;
    B = M[i].second;
    rep(j,H+1) {
      if (dp[j] == 1e9)
        continue;
      int k = min(j+A, H);
      dp[k] = min(dp[k], dp[j]+B);
    }
  }
  print(dp[H]);
  return 0;
}
