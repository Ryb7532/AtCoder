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
  int H,W,N;
  cin >> H >> W >> N;
  vector<int> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  vector<vector<int>> res(H, vector<int>(W));
  int h=0, w=0;
  rep(i,N) {
    int a = A[i];
    while (a != 0) {
      res[h][w] = i+1;
      if (h%2) {
        if (w == 0) {
          h++;
        } else {
          w--;
        }
      } else {
        if (w == W-1) {
          h++;
        } else {
          w++;
        }
      }
      a--;
    }
  }
  rep(i,H) {
    cout << res[i][0];
    rep(j,W-1) {
      cout << " " << res[i][j+1];
    }
    cout << endl;
  }
  return 0;
}
