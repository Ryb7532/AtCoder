#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

int main() {
  int N,M;
  cin >> N >> M;
  vector<int> S(M), T(M);
  vector<vector<int>> E(N);
  rep(i,M) {
    cin >> S[i] >> T[i];
    E[--S[i]].push_back(i);
    T[i]--;
  }
  vector<ld> dp(N,0);
  rrep(i,N-1) {
    for (int v: E[i]) {
      dp[i] += (dp[T[v]] + 1) / E[i].size();
    }
  }
  vector<ld> p(N,0);
  p[0] = 1;
  rep(i,N-1) {
    for (int v: E[i]) {
      p[T[v]] += p[i] / E[i].size();
    }
  }
  ld res = dp[0];
  rep(i,M) {
    if (E[S[i]].size() == 1)
      continue;
    ld tmp = 0;
    tmp = dp[0] - p[S[i]] * dp[S[i]];
    for (int v: E[S[i]]) {
      if (i == v)
        continue;
      tmp += p[S[i]] * (dp[T[v]] + 1) / (E[S[i]].size() - 1);
    }
    res = min(res, tmp);
  }
  print(fix(10) << res);
  return 0;
}