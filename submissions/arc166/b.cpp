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
  vector<ll> S(3);
  cin >> N;
  rep(i,3) {
    cin >> S[i];
  }
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  vector<vector<ll>> dp(N+1, vector<ll>(8, 2e18+5));
  dp[0][0] = 0;
  map<int,ll> lcm;
  rep(i,8) {
    ll l = 1;
    rep(j,3) {
      if (i&(1<<j)) {
        ll g = gcd(l, S[j]);
        l = l * S[j] / g;
      }
    }
    lcm[i] = l;
  }
  rep(i,N) {
    rep(j,8) {
      dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
      rep(k,8) {
        ll m = lcm[k];
        ll cost = (m - (A[i]%m)) % m;
        dp[i+1][j|k] = min(dp[i+1][j|k], dp[i][j]+cost);
      }
    }
  }
  print(dp[N][7]);
  return 0;
}