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
  int H,W,N,h,w;
  cin >> H >> W >> N >> h >> w;
  vector<vector<int>> A(H+1, vector<int>(W+1, 0));
  vector<int> cnt(N+1);
  rep(i,H) {
    rep(j,W) {
      cin >> A[i][j];
    }
  }
  vector<vector<int>> res(H-h+1, vector<int>(W-w+1));
  rep(i,H-h+1) {
    rep(k,N+1) {
      cnt[k] = 0;
    }
    rep(j,H) {
      rep(k,W) {
        if (i<=j && j<i+h && k<w)
          continue;
        cnt[A[j][k]]++;
      }
    }
    rep(j,W-w+1) {
      int r = 0;
      rep(k,N) {
        if (cnt[k+1]>0)
          r++;
      }
      res[i][j] = r;
      rep(k,h) {
        cnt[A[i+k][j]]++;
        cnt[A[i+k][j+w]]--;
      }
    }
  }
  rep(i,H-h+1) {
    rep(j,W-w+1) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
