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
  int N;
  scan(N);
  vector<int> A(N), B(N);
  int sum = 0;
  rep(i,N) {
    scan(A[i], B[i]);
    sum += B[i];
  }
  if (sum % 3 != 0) {
    print(-1);
    return 0;
  }
  int target = sum / 3;
  vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(target+1, vector<int>(target+1, N+1)));
  dp[0][0][0] = 0;
  rep(i,N) {
    rep(j,target+1) {
      rep(k,target+1) {
        if (A[i] == 1) {
          if (j + B[i] <= target) {
            chmin(dp[i+1][j+B[i]][k], dp[i][j][k]);
          }
          if (k + B[i] <= target) {
            chmin(dp[i+1][j][k+B[i]], dp[i][j][k]+1);
          }
          chmin(dp[i+1][j][k], dp[i][j][k]+1);
        }
        if (A[i] == 2) {
          if (j + B[i] <= target) {
            chmin(dp[i+1][j+B[i]][k], dp[i][j][k]+1);
          }
          if (k + B[i] <= target) {
            chmin(dp[i+1][j][k+B[i]], dp[i][j][k]);
          }
          chmin(dp[i+1][j][k], dp[i][j][k]+1);
        }
        if (A[i] == 3) {
          if (j + B[i] <= target) {
            chmin(dp[i+1][j+B[i]][k], dp[i][j][k]+1);
          }
          if (k + B[i] <= target) {
            chmin(dp[i+1][j][k+B[i]], dp[i][j][k]+1);
          }
          chmin(dp[i+1][j][k], dp[i][j][k]);
        }
      }
    }
  }
  int res = N+1;
  chmin(res, dp[N][target][target]);
  print(res > N ? -1 : res);
  return 0;
}