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
  vector<int> a(N);
  rep(i,N) {
    cin >> a[i];
  }
  vector<vector<int>> info(N+1, vector<int>(4,0)); // cnt, top, top_n, top_start
  rep(i,N) {
    if (info[i][1] != a[i]) {
      info[i+1] = {info[i][0]+1, a[i], 1, i};
    } else {
      if (info[i][2]+1 == a[i]) {
        info[i+1] = info[info[i][3]];
      } else {
        info[i+1][0] = info[i][0]+1;
        info[i+1][1] = info[i][1];
        info[i+1][2] = info[i][2]+1;
        info[i+1][3] = info[i][3];
      }
    }
    print(info[i+1][0]);
  }
  return 0;
}
