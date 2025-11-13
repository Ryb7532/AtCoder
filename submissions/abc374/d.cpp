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
  int N, S, T;
  scan(N, S, T);
  N++;
  vector<ld> A(N+1), B(N+1), C(N+1), D(N+1);
  rep(i, 1, N) scan(A[i], B[i], C[i], D[i]);
  A[0] = 0; B[0] = 0; C[0] = 0; D[0] = 0;
  vector<vector<vector<ld>>> dp(1<<N, vector<vector<ld>>(N, vector<ld>(2, 1e18)));
  dp[1][0][0] = 0;
  ld res = 1e18;
  ld dist = 0;
  rep(i, N) {
    ld dx = A[i] - C[i], dy = B[i] - D[i];
    dist += sqrtl(dx*dx + dy*dy);
  }
  rep(i, 1, 1<<N) {
    rep(l, 1, N) {
      if (i&(1<<l)) continue;
      rep(j, N) {
        if (!(i&(1<<j))) continue;
        rep(k, 2) {
          rep(m, 2) {
            ld dx, dy;
            if (k == 0) {
              dx = A[j];
              dy = B[j];
            } else {
              dx = C[j];
              dy = D[j];
            }
            if (m == 1) {
              dx -= A[l];
              dy -= B[l];
            } else {
              dx -= C[l];
              dy -= D[l];
            }
            chmin(dp[i|1<<l][l][m], dp[i][j][k] + sqrtl(dx*dx + dy*dy));
          }
        }
      }
    }
  }
  rep(i, 1, N) {
    rep(j, 2) {
      chmin(res, dp[(1<<N)-1][i][j]);
    }
  }
  res /= S;
  res += dist / T;
  cout << fix(10) << res << endl;
  return 0;
}