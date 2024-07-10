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
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
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
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}

int main() {
  int N;
  cin >> N;
  using v = vector<ll>;
  using vv = vector<v>;
  vv P(N, v(N)), R(N, v(N-1)), D(N-1, v(N));
  fore(V,P) fore(a,V) cin >> a;
  fore(V,R) fore(a,V) cin >> a;
  fore(V,D) fore(a,V) cin >> a;
  vector<ll> Q;
  rep(i,N) rep(j,N) Q.push_back(P[i][j]);
  sort(all(Q));
  Q.erase(unique(all(Q)), Q.end());
  int M = Q.size();
  vector<vector<int>> I(N, vector<int>(N));
  rep(i,N) {
    rep(j,N) {
      I[i][j] = lower_bound(all(Q),P[i][j])-Q.begin();
    }
  }
  using pll = pair<ll,ll>;
  using vp = vector<pll>;
  using vvp = vector<vp>;
  vector<vvp> dp(N, vvp(N, vp(M, {1e18,0})));
  dp[0][0][I[0][0]] = {0,0};
  auto f = [](pll v, ll nt, ll nc) {
    return (v.first > nt || (v.first == nt && v.second > nc));
  };
  rep(i,N) {
    rep(j,N) {
      rep(k,M) {
        auto [t,c] = dp[i][j][k];
        if (i+1 < N) {
          ll nc = c+D[i][j];
          ll nt = 0;
          if (nc > 0)
            nt = (nc-1)/Q[k]+1;
          nc -= Q[k]*nt;
          nt += t;
          if (f(dp[i+1][j][max(k,I[i+1][j])],nt,nc))
            dp[i+1][j][max(k,I[i+1][j])] = {nt,nc};
        }
        if (j+1 < N) {
          ll nc = c+R[i][j];
          ll nt = 0;
          if (nc > 0)
            nt = (nc-1)/Q[k]+1;
          nc -= Q[k]*nt;
          nt += t;
          if (f(dp[i][j+1][max(k,I[i][j+1])],nt,nc))
            dp[i][j+1][max(k,I[i][j+1])] = {nt,nc};
        }
      }
    }
  }
  ll res = 1e18;
  rep(k,M) {
    chmin(res, dp[N-1][N-1][k].first+2*(N-1));
  }
  print(res);
  return 0;
}