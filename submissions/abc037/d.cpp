#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int H, W;
ll a[1000][1000];
ll b[1000][1000];
bool c[1000][1000];
const ll MOD = 1e9+7;

void dfs(int x, int y) {
  if (c[x][y])
    return;
  int cnt = 1;
  if (x>0 && a[x-1][y]>a[x][y]) {
    dfs(x-1, y);
    cnt += b[x-1][y];
    cnt %= MOD;
  }
  if (x<H-1 && a[x+1][y]>a[x][y]) {
    dfs(x+1, y);
    cnt += b[x+1][y];
    cnt %= MOD;
  }
  if (y>0 && a[x][y-1]>a[x][y]) {
    dfs(x, y-1);
    cnt += b[x][y-1];
    cnt %= MOD;
  }
  if (y<W-1 && a[x][y+1]>a[x][y]) {
    dfs(x, y+1);
    cnt += b[x][y+1];
    cnt %= MOD;
  }
  c[x][y] = true;
  b[x][y] = cnt;
  return;
}

int main() {
  cin >> H >> W;
  for (int i=0; i<H; i++)
    for (int j=0; j<W; j++)
      cin >> a[i][j];
  for (int i=0; i<H; i++)
    for (int j=0; j<W; j++)
      dfs(i, j);
  ll ans = 0;
  for (int i=0; i<H; i++)
    for (int j=0; j<W; j++) {
      ans += b[i][j];
      ans %= MOD;
    }
  cout << ans << endl;
  return 0;
}
