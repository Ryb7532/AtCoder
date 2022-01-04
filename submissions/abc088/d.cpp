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
  vector<string> S(H);
  vector<vector<int>> C(H, vector<int>(W, -1));
  rep(i,H) {
    cin >> S[i];
  }
  int black = 0;
  rep(i,H) {
    rep(j,W) {
      black += (S[i][j]=='#');
    }
  }
  C[0][0] = 1;
  queue<pair<int,int>> q;
  q.push({0,0});
  while(!q.empty()) {
    auto f = q.front();
    q.pop();
    int h = f.first, w = f.second;
    if (h>0 && S[h-1][w]=='.' && C[h-1][w]==-1) {
      C[h-1][w] = C[h][w]+1;
      q.push({h-1,w});
    }
    if (h<H-1 && S[h+1][w]=='.' && C[h+1][w]==-1) {
      C[h+1][w] = C[h][w]+1;
      q.push({h+1,w});
    }
    if (w>0 && S[h][w-1]=='.' && C[h][w-1]==-1) {
      C[h][w-1] = C[h][w]+1;
      q.push({h,w-1});
    }
    if (w<W-1 && S[h][w+1]=='.' && C[h][w+1]==-1) {
      C[h][w+1] = C[h][w]+1;
      q.push({h,w+1});
    }
  }
  if (C[H-1][W-1] == -1) {
    print(-1);
    return 0;
  }
  print(H*W-C[H-1][W-1]-black);
  return 0;
}
