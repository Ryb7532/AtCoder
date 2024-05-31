#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep1(n) rep2(_,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep1(n) rrep2(_,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define out1(a) cout << (a) << endl
#define out2(a,b) cout << (a) << " " << (b) << endl
#define out3(a,b,c) cout << (a) << " " << (b) << " " << (c) << endl
#define print(...) GET_MACRO(__VA_ARGS__,out3,out2,out1)(__VA_ARGS__)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyn(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

int main() {
  string S;
  cin >> S;
  int L = S.size();
  vector<int> N(L);
  rep(i,L) {
    N[i] = S[i]-'0';
  }
  using v = vector<pair<ll,ll>>;
  using vv = vector<v>;
  using vvv = vector<vv>;
  using vvvv = vector<vvv>;
  int M = 9*(L+1);
  vvvv dp(L+1, vvv(M+1, vv(M+1, v(M, {0,0}))));
  rep(i,1,M) {
    dp[0][i][i][0].second = 1;
  }
  rep(n,L) {
    rep(s,1,M) {
      rep(r,M+1) {
        rep(m,M) {
          rep(d,N[n]) {
            if (r < d)
              break;
            dp[n+1][s][r-d][(10*m+d)%s].first += dp[n][s][r][m].second;
          }
          int d = N[n];
          if (r >= d)
            dp[n+1][s][r-d][(10*m+d)%s].second += dp[n][s][r][m].second;
          rep(d,10) {
            if (r < d)
              break;
            dp[n+1][s][r-d][(10*m+d)%s].first += dp[n][s][r][m].first;
          }
        }
      }
    }
  }
  ll res = 0;
  rep(s,1,M) {
    res += dp[L][s][0][0].first + dp[L][s][0][0].second;
  }
  print(res);
  return 0;
}