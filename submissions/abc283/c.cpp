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
  string S;
  cin >> S;
  int N = S.size();
  int res = 0;
  int zero = 0;
  rep(i,N) {
    if (S[i] == '0') {
      if (zero > 0) {
        zero = 0;
      } else {
        res++;
        zero++;
      }
    } else {
      res++;
      zero = 0;
    }
  }
  print(res);
  return 0;
}
