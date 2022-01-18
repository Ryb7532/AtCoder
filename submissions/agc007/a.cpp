#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
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
  vector<string> A(H);
  vector<vector<bool>> used(H, vector<bool>(W,false));
  rep(i,H) {
    cin >> A[i];
  }
  int x = 0, y = 0;
  used[0][0] = true;
  while (true) {
    if (x+1<H && A[x+1][y] == '#') {
      x++;
      used[x][y] = true;
      continue;
    } else if (y+1<W && A[x][y+1] == '#') {
      y++;
      used[x][y] = true;
      continue;
    }
    break;
  }
  bool flag = true;
  rep(i,H) {
    rep(j,W) {
      if (!used[i][j] && A[i][j]=='#')
        flag = false;
    }
  }
  print((flag ? "Possible" : "Impossible"));
  return 0;
}
