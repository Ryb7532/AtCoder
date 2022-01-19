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
  int N;
  cin >> N;
  vector<string> S(N);
  vector<vector<bool>> flag(N, vector<bool>(N,false));
  rep(i,N) {
    cin >> S[i];
  }
  rep(i,N) {
    rep(j,N) {
      bool f = true;
      rep(k,N) {
        if (S[(i+k)%N][j] != S[i][(j+k)%N]) {
          f = false;
          break;
        }
      }
      flag[i][j] = f;
    }
  }
  int res = 0;
  rep(i,N) {
    bool f = true;
    rep(j,N) {
      if (!flag[(i+j)%N][j])
        f = false;
    }
    if (f)
      res += N;
  }
  print(res);
  return 0;
}
