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
  vector<string> S(2);
  cin >> S[0] >> S[1];
  rep(i,2) {
    rep(j,2) {
      if (S[i][j] == '#' && S[(i+1)%2][j] == '.' && S[i][(j+1)%2] == '.') {
        print(No);
        return 0;
      }
    }
  }
  print(Yes);
  return 0;
}
