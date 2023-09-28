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
  vector<vector<ll>> D(N, vector<ll>(N, 0));
  rep(i,N-1) {
    rep(j,N-1-i) {
      ll d;
      cin >> d;
      D[i][i+1+j] = d;
    }
  }
  ll res = 0;
  vector<ll> dp(1<<N, 0);
  rep(s,1<<N) {
    rep(i,N) {
      if (s & (1<<i))
        continue;
      rep(j,i+1,N) {
        if (s & (1<<j))
          continue;
        dp[s|(1<<i)|(1<<j)] = max(dp[s|(1<<i)|(1<<j)], dp[s]+D[i][j]);
        res = max(res, dp[s|(1<<i)|(1<<j)]);
      }
    }
  }
  print(res);
  return 0;
}