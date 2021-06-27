#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int A,B,C;
  cin >> A >> B >> C;
  vec<vec<vec<ld>>> dp(101,vec<vec<ld>>(101,vec<ld>(101,0)));
  for (ld a=99; a>=0; a-=1) {
    for (ld b=99; b>=0; b-=1) {
      for (ld c=99; c>=0; c-=1) {
        dp[a][b][c] = a*(dp[a+1][b][c]+1) + b*(dp[a][b+1][c]+1) + c*(dp[a][b][c+1]+1);
        dp[a][b][c] /= a+b+c;
      }
    }
  }
  print(fix(9) << dp[A][B][C]);
  return 0;
}
