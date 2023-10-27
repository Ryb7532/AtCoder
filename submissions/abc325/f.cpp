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
  vector<int> D(N);
  rep(i,N) {
    cin >> D[i];
  }
  vector<int> L(2), K(2);
  vector<ll> C(2);
  rep(i,2) {
    cin >> L[i] >> C[i] >> K[i];
  }
  if (K[0] > K[1]) {
    swap(L[0], L[1]);
    swap(C[0], C[1]);
    swap(K[0], K[1]);
  }
  const ll INF = 1e9;
  vector<vector<int>> dp(N+1, vector<int>(K[0]+1, INF));
  dp[0][0] = 0;
  rep(i,N) {
    rep(j,K[0]+1) {
      if (dp[i][j] == 1e9)
        break;
      rep(k,K[0]+1) {
        if (j+k>K[0] || k > (D[i]-1)/L[0]+1)
          break;
        dp[i+1][j+k] = min(dp[i+1][j+k], dp[i][j]+max(D[i]-k*L[0]+L[1]-1, 0)/L[1]);
      }
    }
  }
  ll res = 1e18;
  rep(i,K[0]+1) {
    int j = dp[N][i];
    if (j <= K[1])
      res = min(res, C[0]*i+C[1]*j);
  }
  if (res == 1e18)
    res = -1;
  print(res);
  return 0;
}