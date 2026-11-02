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
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define printyn(f) cout << ((f) ? "Yes" : "No") << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}
void print() {cout << endl;}
template<typename Arg, typename... Args> void print(const Arg a, const Args... b) {
  cout << a;
  (cout << ... << (cout << ' ', b)) << endl;
}
template<class... T> void scan(T&... a) {(cin >> ... >> a);}

int main() {
  int N,M;
  scan(N,M);
  vector<ll> A(N);
  ll S = 0;
  fore(a, A) {
    scan(a);
    S += a;
  }
  ll T = S/M;
  ll MAX = 1e15;
  vector<vector<ll>> dp(M+1, vector<ll>(1<<N, MAX));
  dp[0][0] = 0;
  rep(i,1,M+1) {
    rep(j,1<<N) {
      if (dp[i-1][j] >= MAX)
        continue;
      ll s = 0;
      rep(k,N) {
        if (j & (1<<k))
          s += A[k];
      }
      if (s == T * i) {
        chmin(dp[i][j], dp[i-1][j]);
      } else if (s > T * i) {
        chmin(dp[i][j], dp[i-1][j]+1);
      } else {
        rep(k,N) {
          if (j & (1<<k))
            continue;
          chmin(dp[i-1][j|(1<<k)], dp[i-1][j]);
        }
      }
    }
  }
  print(dp[M][(1<<N)-1]);
  return 0;
}