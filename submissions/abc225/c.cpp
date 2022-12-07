#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N,M;
  cin >> N >> M;
  vec<vec<int>> B(N, vec<int>(M));
  rep(i,N) {
    rep(j,M) {
      cin >> B[i][j];
    }
  }
  bool flag = true;
  rep(j,M-1) {
    if (B[0][j]+1!=B[0][j+1])
      flag = false;
  }
  if ((B[0][0]-1)%7 > 7-M)
    flag = false;
  rep(i,N-1) {
    rep(j,M) {
      if (B[i][j]+7 != B[i+1][j])
        flag = false;
    }
  }
  print((flag ? Yes : No));
  return 0;
}
