#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int H,W,N,M;
  cin >> H >> W >> N >> M;
  vec<vec<int>> bright1(H, vec<int>(W, 0)), bright2(H, vec<int>(W, 0));
  vec<pair<int,int>> light(N);
  int a,b;
  rep(i,N) {
    cin >> a >> b;
    a--;
    b--;
    light[i] = {a,b};
  }
  rep(i,M) {
    cin >> a >> b;
    a--;
    b--;
    bright1[a][b]--;
    bright2[a][b]--;
  }
  rep(i,N) {
    auto [a,b] = light[i];
    if (bright1[a][b] == 0) {
      int j = b;
      while (j<W && bright1[a][j]==0) {
        bright1[a][j]++;
        j++;
      }
      j = b-1;
      while (j>=0 && bright1[a][j]==0) {
        bright1[a][j]++;
        j--;
      }
    }
    if (bright2[a][b] == 0) {
      int j = a;
      while (j<H && bright2[j][b]==0) {
        bright2[j][b]++;
        j++;
      }
      j = a-1;
      while (j>=0 && bright2[j][b]==0) {
        bright2[j][b]++;
        j--;
      }
    }
  }
  int res = 0;
  rep(i,H) {
    rep(j,W) {
      if (bright1[i][j]>0 || bright2[i][j]>0)
        res++;
    }
  }
  print(res);
  return 0;
}
