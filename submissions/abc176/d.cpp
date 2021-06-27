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
int H, W;
string S[1000];
vvi cnt(1000,vi(1000,-1));

void bfs(int h,int w) {
  queue<tuple<int,int,int>> q1,q2;
  q1.push({h,w,0});
  q2.push({h,w,0});
  while (1) {
    while (!q1.empty()) {
      auto t = q1.front();
      int x = get<0>(t), y = get<1>(t), c = get<2>(t);
      q1.pop();
      if (cnt[x][y] >= 0) {
        continue;
      }
      cnt[x][y] = c;
      if (x > 0 && S[x - 1][y] == '.')
        q1.push({x - 1, y, c});
      if (x < H-1 && S[x + 1][y] == '.')
        q1.push({x + 1, y, c});
      if (y > 0 && S[x][y - 1] == '.')
        q1.push({x, y - 1, c});
      if (y < W-1 && S[x][y + 1] == '.')
        q1.push({x, y + 1, c});
      reps(i,max(x-2,0), min(x+3,H)) {
        reps(j,max(y-2,0),min(y+3,W)) {
          if (S[i][j] == '.' && cnt[i][j] == -1) {
            q2.push({i,j,c+1});
            cnt[i][j]--;
          }
        }
      }
    }
    while (!q2.empty()) {
      auto t = q2.front();
      int x = get<0>(t), y = get<1>(t), c = get<2>(t);
      q2.pop();
      if (cnt[x][y]>=0)
        continue;
      q1.push({x,y,c});
    }
    if (q1.empty())
      break;
  }
}

int main() {
  cin >> H >> W;
  int Ch, Cw, Dh, Dw;
  cin >> Ch >> Cw >> Dh >> Dw;
  Ch--; Cw--; Dh--; Dw--;
  rep(i,H) cin >> S[i];
  bfs(Ch,Cw);
  print((cnt[Dh][Dw]<0)?-1:cnt[Dh][Dw]);
  return 0;
}
