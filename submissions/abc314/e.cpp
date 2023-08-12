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
  int N,M;
  cin >> N >> M;
  vector<ld> C(N);
  vector<vector<int>> S(N);
  vector<int> zero(N, 0);
  rep(i,N) {
    int P;
    cin >> C[i] >> P;
    rep(j,P) {
      int s;
      cin >> s;
      if (s == 0)
        zero[i]++;
      else
        S[i].push_back(s);
    }
  }
  vector<ld> dp(M, 1e18);
  rrep(i,M) {
    vector<ld> tmp(N,0.0);
    rep(j,N) {
      for (int e: S[j]) {
        if (e == 0)
          continue;
        tmp[j] += (i+e >= M) ? 0 : dp[i+e] / S[j].size();
      }
      tmp[j] += (ld)C[j] * (S[j].size()+zero[j]) / S[j].size();
    }
    rep(j,N)
      dp[i] = min(dp[i], tmp[j]);
  }
  print(fix(10) << dp[0]);
  return 0;
}
