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
  int N, M, x, y;
  cin >> N >> M;
  bool ac[N][N];
  rep(i, N)
    rep(j, N)
      ac[i][j] = false;
  rep(i, M) {
    cin >> x >> y;
    x--; y--;
    ac[x][y] = ac[y][x] = true;
  }
  int ans = 0;
  rep(i, (1<<N)) {
    bool c = true;
    int cnt = 0;
    rep(j, N) {
      if ((i&(1<<j)) == 0)
        continue;
      cnt++;
      reps(k, j+1, N) {
        if ((i&(1<<k)) == 0)
          continue;
        if (!ac[j][k])
          c = false;
      }
    }
    if (c)
      ans = max(ans, cnt);
  }
  print(ans);
  return 0;
}
