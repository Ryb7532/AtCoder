#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  int H,W;
  cin >> H >> W;
  int C[H+1][W+1];
  rep(i,H+1) {
    rep(j,W+1) {
      if (i==0 || j==0) {
        C[i][j] = 0;
        continue;
      }
      int c;
      cin >> c;
      if ((i+j)%2)
        C[i][j] = c;
      else
        C[i][j] = -c;
    }
  }
  rep(i,H+1) {
    rep1(j,W) {
      C[i][j] += C[i][j-1];
    }
  }
  rep1(i,H) {
    rep(j,W+1) {
      C[i][j] += C[i-1][j];
    }
  }
  int ans = 0;
  rep(h1,H) {
    rep(w1,W) {
      reps(h2,h1+1,H+1) {
        reps(w2,w1+1,W+1) {
          if (C[h2][w2] - C[h1][w2] - C[h2][w1] + C[h1][w1] == 0)
            ans = max((h2-h1)*(w2-w1),ans);
        }
      }
    }
  }
  print(ans);
  return 0;
}
