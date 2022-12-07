#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


int main() {
  int H, W, K;
  cin >> H >> W >> K;
  string c[H];
  rep(i, H) {
    cin >> c[i];
  }
  int ans = 0;
  rep(i, (1<<H)) {
    rep(j, (1<<W)) {
      int cnt = 0;
      rep(k, H) {
        if ((i&(1<<k)) != 0)
          continue;
        rep(l, W) {
          if ((j&(1<<l)) != 0)
            continue;
          if (c[k][l] == '#')
            cnt++;
        }
      }
      if (cnt == K)
        ans++;
    }
  }
  print(ans);
  return 0;
}
