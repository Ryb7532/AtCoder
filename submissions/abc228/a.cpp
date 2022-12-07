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
  int S, T, X;
  cin >> S >> T >> X;
  bool XgeS = X >= S, XltT = X < T, on;
  if (S<T) {
    on = XgeS && XltT;
  } else {
    on = XgeS || XltT;
  }
  print((on ? Yes : No));
  return 0;
}
