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
  string S;
  cin >> N;
  vector<int> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  cin >> S;
  ll res = 0;
  vector<vector<ll>> dp0(N+1, vector<ll>(3, 0)), dp1(N+1, vector<ll>(8, 0));
  rep(i,N) {
    rep(j,3)
      dp0[i+1][j] += dp0[i][j];
    if (S[i] == 'M') {
      dp0[i+1][A[i]]++;
    }
  }
  rep(i,N) {
    rep(j,8)
      dp1[i+1][j] += dp1[i][j];
    if (S[i] == 'E') {
      rep(j,3) {
        dp1[i+1][(1<<A[i]) | (1<<j)] += dp0[i][j];
      }
    }
  }
  rep(i,N) {
    if (S[i] == 'X') {
      rep(j,8) {
        int k = 0;
        while ((1<<k) & ((1<<A[i]) | j)) {
          k++;
        }
        res += k * dp1[i+1][j];
      }
    }
  }
  print(res);
  return 0;
}
