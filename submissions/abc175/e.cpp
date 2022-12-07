#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  int R,C,K;
  cin >> R >> C >> K;
  vector<vector<ll>> item(R+1,vector<ll>(C+1,0));
  rep(i,K) {
    int r,c; ll v;
    cin >> r >> c >> v;
    r--; c--;
    item[r][c] = v;
  }
  vector<vector<vector<ll>>> dp(R+1,vector<vector<ll>>(C+1,vector<ll>(4,0)));
  repr(i,R,0) {
    repr(j,C,0) {
      repr(k,3,0) {
        dp[i][j][k] = max(dp[i+1][j][0]+item[i][j],max(dp[i][j+1][k+1]+item[i][j],dp[i][j+1][k]));
      }
    }
  }
  print(dp[0][0][0]);
  return 0;
}
