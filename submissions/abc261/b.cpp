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
  int N;
  cin >> N;
  vector<string> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  bool flag = true;
  rep(i,N) {
    rep(j,N) {
      if (i == j)
        continue;
      if (A[i][j] == 'D' && A[j][i] != 'D')
        flag = false;
      if (A[i][j] == 'W' && A[j][i] != 'L')
        flag = false;
      if (A[i][j] == 'L' && A[j][i] != 'W')
        flag = false;
    }
  }
  print((flag ? "correct" : "incorrect"));
  return 0;
}
