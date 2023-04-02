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


int main() {
  int N,M;
  cin >> N >> M;
  vector<vector<bool>> have(M, vector<bool>(N));
  rep(i,M) {
    int C;
    cin >> C;
    rep(_,C) {
      int a;
      cin >> a;
      a--;
      have[i][a] = true;
    }
  }
  int res = 0;
  rep(i,(1<<M)) {
    vector<bool> used(N, false);
    rep(j,M) {
      if (i&(1<<j)) {
        rep(k,N) {
          if (have[j][k])
            used[k] = true;
        }
      }
    }
    bool flag = true;
    rep(j,N) {
      flag &= used[j];
    }
    if (flag)
      res++;
  }
  print(res);
  return 0;
}
