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
  int N,X;
  ll K;
  scan(N,X,K);
  vector<ll> P(N), U(N), C(N);
  vector<int> idx(N);
  rep(i,N) scan(P[i], U[i], C[i]), idx[i] = i;
  sort(all(idx), [&](int a, int b) {return C[a] < C[b];});
  int minus = 0;
  int prev = 0;
  fore(i,idx) {
    if (prev != C[i]) {
      minus += C[i]-prev-1;
      prev = C[i];
    }
    C[i] -= minus;
  }
  vector<vector<ll>> dp(N+1, vector<ll>(X+1, -1e18));
  dp[0][0] = 0;
  rep(i,N) {
    ll p = P[idx[i]], u = U[idx[i]], c = C[idx[i]];
    rrep(j,X+1) {
      if (j-p < 0) continue;
      chmax(dp[c][j], dp[c-1][j-p]+u+K);
      chmax(dp[c][j], dp[c][j-p]+u);
    }
    if (i >= N-1 || C[idx[i]] != C[idx[i+1]]) {
      rep(j,X+1) chmax(dp[c][j], dp[c-1][j]);
    }
  }
  ll res = 0;
  rep(j,X+1) chmax(res, dp[C[idx[N-1]]][j]);
  print(res);
  return 0;
}