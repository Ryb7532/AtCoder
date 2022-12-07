#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


int main() {
  int R, C, K;
  cin >> R >> C >> K;
  bool s[K][R][C];
  string S;
  rep(i, R) {
    cin >> S;
    rep(j, C) {
      s[0][i][j] = (S[j] == 'x');
    }
  }
  rep1(k, K-1) {
    rep(i, R) {
      rep(j, C) {
        s[k][i][j] = s[k-1][i][j];
        if (i>0)
          s[k][i][j] =  s[k][i][j] || s[k-1][i-1][j];
        if (i<R-1)
          s[k][i][j] =  s[k][i][j] || s[k-1][i+1][j];
        if (j>0)
          s[k][i][j] =  s[k][i][j] || s[k-1][i][j-1];
        if (j<C-1)
          s[k][i][j] =  s[k][i][j] || s[k-1][i][j+1];
      }
    }
  }
  int ans = 0;
  reps(i, K-1, R-K+1) {
    reps(j, K-1, C-K+1) {
      if (!s[K-1][i][j])
        ans++;
    }
  }
  print(ans);
  return 0;
}
