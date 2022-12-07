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
  string X;
  cin >> X;
  int N = X.size(), res = 0, cnts = 0;
  rep(i,N) {
    if (X[i] == 'S') {
      cnts++;
    } else {
      if (cnts == 0) {
        res++;
      } else {
        cnts--;
      }
    }
  }
  print(res+cnts);
  return 0;
}
