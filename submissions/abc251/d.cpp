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
  int W;
  cin >> W;
  print(3*99+1);
  int base = 1;
  rep(_,3) {
    rep(i,99) {
      cout << (i+1)*base << " ";
    }
    base *= 100;
  }
  cout << base << endl;
  return 0;
}
