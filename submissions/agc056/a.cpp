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
  vector<vector<bool>> res(N, vector<bool>(N, false));
  rep(i,N) {
    rep(j,3) {
      res[i][(i*3+j)%N] = true;
    }
  }
  if (N%3!=0) {
    swap(res[0], res[N/3-1]);
    swap(res[N-1], res[N-N/3]);
  }
  rep(i,N) {
    rep(j,N) {
      cout << (res[i][j] ? '#' : '.');
    }
    cout << endl;
  }
  return 0;
}
