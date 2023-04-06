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
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int H,W;
vector<vector<int>> A(10, vector<int>(10));
set<int> used;
ll res = 0;

void dfs(int x, int y) {
  if (used.find(A[x][y]) != used.end())
    return ;
  if (x == H-1 && y == W-1) {
    res++;
    return ;
  }
  used.insert(A[x][y]);
  if (x != H-1)
    dfs(x+1, y);
  if (y != W-1)
    dfs(x,y+1);
  used.erase(used.find(A[x][y]));
}

int main() {
  cin >> H >> W;
  rep(i,H) {
    rep(j,W) {
      cin >> A[i][j];
    }
  }
  dfs(0,0);
  print(res);
  return 0;
}
