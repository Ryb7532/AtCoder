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
  int H1,W1;
  cin >> H1 >> W1;
  vector<vector<int>> A(H1, vector<int>(W1));
  rep(i,H1) {
    rep(j,W1) {
      cin >> A[i][j];
    }
  }
  int H2,W2;
  cin >> H2 >> W2;
  vector<vector<int>> B(H2, vector<int>(W2));
  rep(i,H2) {
    rep(j,W2) {
      cin >> B[i][j];
    }
  }
  bool res = false;
  rep(i,1<<H1) {
    int bh1 = 0;
    rep(j,H1) {
      if (i & (1<<j))
        bh1++;
    }
    if (bh1 != H2)
      continue;
    rep(j,1<<W1) {
      int bw1 = 0;
      rep(k,W1) {
        if (j & (1<<k))
          bw1++;
      }
      if (bw1 != W2)
        continue;
      bool flag = true;
      int h = 0;
      rep(k,H2) {
        while (!(i & (1<<h))) h++;
        int w = 0;
        rep(l,W2) {
          while (!(j & (1<<w))) w++;
          if (A[h][w] != B[k][l])
            flag = false;
          w++;
        }
        h++;
      }
      if (flag)
        res = true;
    }
  }
  print((res ? Yes : No));
  return 0;
}
