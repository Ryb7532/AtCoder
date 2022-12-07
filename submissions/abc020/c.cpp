#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()
int H, W, T;
string S[10];
const int MAX_V = 100;
const ll INF = 2e10;
int V;
ll d[MAX_V][MAX_V];

void init(int m) {
  rep(i, V)
    rep(j, V)
      if (i != j)
        d[i][j] = INF;
  rep(i, H) {
    rep(j, W) {
      if (i > 0) {
        if (S[i-1][j] == '#')
          d[W*i+j][W*(i-1)+j] = m;
        else
          d[W*i+j][W*(i-1)+j] = 1;
      }
      if (i < H-1) {
        if (S[i+1][j] == '#')
          d[W*i+j][W*(i+1)+j] = m;
        else
          d[W*i+j][W*(i+1)+j] = 1;
      }
      if (j > 0) {
        if (S[i][j-1] == '#')
          d[W*i+j][W*i+j-1] = m;
        else
          d[W*i+j][W*i+j-1] = 1;
      }
      if (j < W-1) {
        if (S[i][j+1] == '#')
          d[W*i+j][W*i+j+1] = m;
        else
          d[W*i+j][W*i+j+1] = 1;
      }
    }
  }
}

void warshall_floyd(int m) {
  init(m);
  rep(k, V)
    rep(i, V)
      rep(j, V)
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
}

int main() {
  cin >> H >> W >> T;
  V = H*W;
  rep(i, H) {
    cin >> S[i];
  }
  int s, g;
  rep(i, H) {
    rep(j, W) {
      if (S[i][j] == 'S')
        s = i*W+j;
      if (S[i][j] == 'G')
        g = i*W+j;
    }
  }
  int lb = 1, ub = T+1;
  while (ub-lb > 1) {
    int m = (lb+ub)/2;
    warshall_floyd(m);
    if (d[s][g]<=T)
      lb = m;
    else
      ub = m;
  }
  print(lb);
  return 0;
}
