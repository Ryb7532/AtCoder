#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int H,W;
  cin >> H >> W;
  vector<string> G(H);
  rep(i,H) {
    cin >> G[i];
  }
  vector<vector<bool>> visited(H, vector<bool>(W, false));
  int h=0,w=0;
  while (true) {
    if (visited[h][w]) {
      h = -1;
      break;
    }
    visited[h][w] = true;
    char c = G[h][w];
    if (c == 'U') {
      if (h == 0)
        break;
      h--;
    }
    if (c == 'D') {
      if (h == H-1)
        break;
      h++;
    }
    if (c == 'L') {
      if (w == 0)
        break;
      w--;
    }
    if (c == 'R') {
      if (w == W-1)
        break;
      w++;
    }
  }
  if (h == -1)
    print(-1);
  else
    print(h+1 << ' ' << w+1);
  return 0;
}
