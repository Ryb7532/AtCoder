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
  int N;
  cin >> N;
  vector<ll> A(N), id(N);
  rep(i,N) {
    cin >> A[i];
    id[i] = i;
  }
  auto f = [&](int a, int b) {
    return A[a] > A[b];
  };
  sort(all(id), f);
  vector<vector<ll>> dp(N+1, vector<ll>(N+1,-1e15));
  dp[0][0] = 0;
  rep(i,N) {
    int p = id[i];
    ll a = A[p];
    dp[0][i+1] = dp[0][i] + a*(N-1-i-p);
    rep(j,1,i+1) {
      dp[j][i+1-j] = max(dp[j-1][i+1-j] + a*(p-j+1), dp[j][i-j] + a*(N-1-i+j-p));
    }
    dp[i+1][0] = dp[i][0] + a*(p-i);
  }
  ll res = 0;
  rep(i,N+1) {
    res = max(res, dp[i][N-i]);
  }
  print(res);
  return 0;
}