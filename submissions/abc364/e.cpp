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

int main() {
  int N,X,Y;
  cin >> N >> X >> Y;
  vector<int> A(N), B(N);
  rep(i,N) {
    cin >> A[i] >> B[i];
  }
  vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(N+1, vector<int>(X+1, 1e8)));
  dp[0][0][0] = 0;
  rep(i,N) {
    rep(j,N+1) {
      rep(k,X+1) {
        chmin(dp[i+1][j][k], dp[i][j][k]);
        if (j + 1 <= N && k + A[i] <= X) {
          chmin(dp[i+1][j+1][k+A[i]], dp[i][j][k]+B[i]);
        }
      }
    }
  }
  int res = 0;
  rep(j,N+1) {
    rep(k,X+1) {
      if (dp[N][j][k] <= Y) {
        res = j;
        break;
      }
    }
  }
  print(min(res+1, N));
  return 0;
}