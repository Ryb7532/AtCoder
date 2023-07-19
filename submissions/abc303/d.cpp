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

const ll INF = 1e18;

int main() {
  ll X,Y,Z;
  string S;
  cin >> X >> Y >> Z >> S;
  vector<int> T;
  bool p_cap = false;
  int num = 0;
  for (char c: S) {
    bool cap = c == 'A';
    if (cap == p_cap)
      num++;
    else {
      T.push_back(num);
      p_cap = cap;
      num = 1;
    }
  }
  T.push_back(num);
  int M = T.size();
  vector<vector<ll>> dp(M+1, vector<ll>(2, INF));
  dp[M][0] = dp[M][1] = 0;
  rrep(i,M) {
    dp[i][0] = min(dp[i][0], T[i]*X + min(Z+dp[i+1][0], dp[i+1][1]));
    dp[i][0] = min(dp[i][0], Z+T[i]*Y + min(dp[i+1][0], Z+dp[i+1][1]));
    dp[i][1] = min(dp[i][1], T[i]*Y + min(dp[i+1][0], Z+dp[i+1][1]));
    dp[i][1] = min(dp[i][1], Z+T[i]*X + min(Z+dp[i+1][0], dp[i+1][1]));
  }
  print(dp[0][0]);
  return 0;
}
