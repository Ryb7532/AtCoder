#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

int main() {
  int N;
  cin >> N;
  vector<vector<int>> P(N, vector<int>(5));
  rep(i,N) {
    rep(j,5) {
      cin >> P[i][j];
    }
  }
  int l = 1, u = 1e9+5;
  while (u-l > 1) {
    int m = (u+l)/2;
    vector<vector<bool>> dp(4, vector<bool>(1<<5, false));
    dp[0][0] = true;
    rep(i,N) {
      int p = 0;
      rep(j,5) {
        if (P[i][j] >= m)
          p += 1<<j;
      }
      rrep(j,3) {
        rep(k,1<<5) {
          if (dp[j][k])
            dp[j+1][k|p] = true;
        }
      }
    }
    if (dp[3][31])
      l = m;
    else
      u = m;
  }
  print(l);
  return 0;
}