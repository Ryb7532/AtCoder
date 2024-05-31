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
#define fore(e,v) for (auto &e: v)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

int main() {
  int N,D;
  cin >> N >> D;
  vector<ll> W(N);
  ld avg = 0;
  rep(i,N) {
    cin >> W[i];
    avg += W[i];
  }
  avg /= D;
  vector<vector<ld>> dp(1<<N, vector<ld>(D+1, 1e18));
  rep(i,1<<N) {
    ll s = 0;
    rep(j,N) {
      if (i & (1<<j))
        s += W[j];
    }
    dp[i][1] = (s-avg) * (s-avg);
  }
  rep(j,2,D+1) {
    rep(i,1<<N) {
      for (ll k=i; k!=0; k=(k-1)&i) {
        chmin(dp[i][j], dp[k][j-1]+dp[i-k][1]);
      }
    }
  }
  print(fix(9) << dp[(1<<N)-1][D]/D);
  return 0;
}