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
  int N,L;
  cin >> N >> L;
  vector<vector<int>> res(N, vector<int>(L));
  rep(i,N) {
    int tmp = i;
    res[i][0] = 2;
    for (int j=L-1; j>0; j--) {
      res[i][j] = tmp%3;
      tmp /= 3;
    }
  }
  rep(i,3) {
    rep(j,N) {
      rep(k,L) {
        cout << (res[j][k]+i)%3;
      }
      cout << endl;
    }
  }
  return 0;
}
