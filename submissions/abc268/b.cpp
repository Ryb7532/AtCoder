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
  string S,T;
  cin >> S >> T;
  int s = S.size(), t = T.size();
  bool flag = true;
  if (s > t) {
    flag = false;
  } else {
    rep(i,s) {
      if (S[i] != T[i])
        flag = false;
    }
  }
  print((flag ? Yes : No));
  return 0;
}
