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
  int R,C;
  cin >> R >> C;
  vector<string> B(R);
  rep(i,R) {
    cin >> B[i];
  }
  rep(i,R) {
    rep(j,C) {
      int d = B[i][j]-'0';
      if (!(d > 0 && d <= 9))
        continue;
      rep(k,R) {
        rep(l,C) {
          if (abs(i-k) + abs(j-l) <= d && B[k][l] == '#')
            B[k][l] = '.';
        }
      }
      B[i][j] = '.';
    }
  }
  rep(i,R) {
    print(B[i]);
  }
  return 0;
}
