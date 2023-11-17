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
  int N,K;
  cin >> N >> K;
  vector<int> H(N);
  vector<int> S(N+1);
  rep(i,N) {
    cin >> H[i];
    S[i] = H[i];
  }
  S[N] = 0;
  sort(all(S));
  S.erase(unique(all(S)), S.end());
  int M = S.size();
  const ll INF = 1e18;
  vector dp(N+1, vector(K+1, vector<ll>(M, INF)));
  dp[0][0][0] = 0;
  rep(i,N) {
    int h = lower_bound(all(S), H[i]) - S.begin();
    rep(j,K) {
      rep(k,1,M) {
        dp[i+1][j+1][k] = min(dp[i][j][k-1], dp[i+1][j+1][k-1])+S[k]-S[k-1];
      }
    }
    rep(j,K) {
      ll m = INF;
      rrep(k,M) {
        m = min(m, dp[i][j][k]);
        dp[i+1][j+1][k] = min(dp[i+1][j+1][k], m);
      }
    }
    rep(j,K+1) {
      rep(k,M) {
        dp[i+1][j][h] = min(dp[i+1][j][h], dp[i][j][k] + max(0, S[h]-S[k]));
      }
    }
  }
  ll res = INF;
  rep(j,K+1) {
    rep(k,M) {
      res = min(res, dp[N][j][k]);
    }
  }
  print(res);
  return 0;
}