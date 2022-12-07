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
const int INF = 1e5;
vvi b(2,vi(3)), c(3,vi(2));
vvi status(3,vi(3));

int dfs(int player) {
  int res = -player*INF;
  rep(i,3) {
    rep(j,3) {
      if (status[i][j] == 0) {
        status[i][j] = player;
        int p = dfs(-player);
        if (player>0) {
          res = max(res,p);
        } else {
          res = min(res,p);
        }
        status[i][j] = 0;
      }
    }
  }
  if (abs(res) == INF) {
    res = 0;
    rep(i,2) {
      rep(j,3) {
        if (status[i][j] == status[i+1][j])
          res += b[i][j];
        else
          res -= b[i][j];
      }
    }
    rep(i,3) {
      rep(j,2) {
        if (status[i][j] == status[i][j+1])
          res += c[i][j];
        else
          res -= c[i][j];
      }
    }
  }
  return res;
}

int main() {
  int sum = 0;
  rep(i,2) {
    rep(j,3) {
      cin >> b[i][j];
      sum += b[i][j];
    }
  }
  rep(i,3) {
    rep(j,2) {
      cin >> c[i][j];
      sum += c[i][j];
    }
  }
  int res = dfs(1);
  print((sum+res)/2);
  print((sum-res)/2);
  return 0;
}
