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
  vector<ld> P(N);
  rep(i,N) {
    cin >> P[i];
  }
  vector<ld> dp(N+1, -1e18);
  vector<ld> decay(N+1);
  dp[0] = 0;
  decay[0] = 1;
  rep(i,N) {
    rrep(j,i+1) {
      dp[j+1] = max(dp[j+1], dp[j]*0.9+P[i]);
    }
    decay[i+1] = decay[i]*0.9;
  }
  ld res = -2000;
  rep(i,1,N+1) {
    res = max(res, dp[i]/10/(1-decay[i]) - 1200.0/sqrtl(i));
  }
  print(fix(10) << res);
  return 0;
}