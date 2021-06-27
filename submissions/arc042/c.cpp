#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  int N, P;
  cin >> N >> P;
  int a[N], b[N];
  rep(i,N) {
    cin >> a[i] >> b[i];
  }
  pii dp[N][5101];
  rep(i,N) {
    rep(j,5101) {
      dp[i][j] = {0,0};
    }
  }
  rep(i,N) {
    dp[i][0] = {0,101};
  }
  dp[0][a[0]] = {b[0],a[0]};
  rep1(i,N-1) {
    int ai = a[i], bi = b[i];
    rep(j,5101) {
      if (j<ai) {
        dp[i][j] = dp[i-1][j];
        continue;
      }
      pii d1 = dp[i-1][j], d2 = dp[i-1][j-ai];
      if (j-min(d2.second,ai)>P || d2.second==0) {
        dp[i][j] = d1;
      } else if (d1.first<d2.first+bi) {
        dp[i][j] = {d2.first+bi, min(d2.second,ai)};
      } else if (d1.first == d2.first+bi) {
        dp[i][j] = {d1.first, max(d1.second, min(d2.second,ai))};
      } else {
        dp[i][j] = d1;
      }
    }
  }
  int ans = 0;
  rep(i,5101) {
    if (ans<dp[N-1][i].first) {
      if (i-dp[N-1][i].second<=P) {
        ans = dp[N-1][i].first;
      }
    }
  }
  print(ans);
  return 0;
}
