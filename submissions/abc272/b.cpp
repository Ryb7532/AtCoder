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
  int N,M;
  cin >> N >> M;
  vector<vector<bool>> attend(M, vector<bool>(N, false));
  rep(i,M) {
    int k;
    cin >> k;
    rep(j,k) {
      int x;
      cin >> x;
      attend[i][--x] = true;
    }
  }
  bool res = true;
  rep(i,N) {
    rep(j,N) {
      bool flag = false;
      rep(k,M) {
        if (attend[k][i] && attend[k][j])
          flag = true;
      }
      if (!flag)
        res = false;
    }
  }
  print((res ? Yes : No));
  return 0;
}
