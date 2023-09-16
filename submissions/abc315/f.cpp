#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl

int main() {
  int N;
  cin >> N;
  vector<ld> X(N), Y(N);
  rep(i,N) {
    cin >> X[i] >> Y[i];
  }
  int M = min(N-2, 30);
  vector<vector<ld>> dp(N, vector<ld>(M+1, 1e9));
  dp[0][0] = 0;
  auto d = [&](int a, int b) {
    assert(0 <= a && a < N);
    assert(0 <= b && b < N);
    assert(a < b);
    return sqrtl((X[a]-X[b]) * (X[a]-X[b]) + (Y[a]-Y[b]) * (Y[a]-Y[b]));
  };
  rep(i,1,N) {
    rep(j,M+1) {
      rep(k,j+1) {
        if (i-k-1 < 0)
          break;
        dp[i][j] = min(dp[i][j], dp[i-k-1][j-k] + d(i-k-1, i));
      }
    }
  }
  ld res = dp[N-1][0], C = 1.0;
  rep(i,M) {
    res = min(res, dp[N-1][i+1] + C);
    C *= 2;
  }
  print(fix(10) << res);
  return 0;
}