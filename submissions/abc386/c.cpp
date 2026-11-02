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
  int K;
  string S,T;
  scan(K,S,T);
  int N = S.size(), M = T.size();
  vector<vector<int>> D(N+1, vector<int>(2*K+1,K+1));
  rep(j,K+1) D[0][K+j] = j;
  rep(i,N) {
    rep(j,2*K+1) {
      if (j>0) chmin(D[i+1][j], D[i+1][j-1]+1);
      if (j<2*K) chmin(D[i+1][j], D[i][j+1]+1);
      if (i+j-K>=0 && i+j-K<M) chmin(D[i+1][j], D[i][j]+(S[i]!=T[i+j-K]));
    }
  }
  bool res = false;
  if (M-N+K >= 0 && M-N+K <= 2*K)
    res = D[N][M-N+K] <= K;
  printyn(res);
  return 0;
}