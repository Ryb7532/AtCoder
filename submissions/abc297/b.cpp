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
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  string S;
  cin >> S;
  int N = 8;
  bool flag = true;
  int b1=-1, b2=-1, k=-1, r1=-1, r2=-1;
  rep(i,N) {
    if (S[i] == 'B') {
      if (b1 != -1) {
        b2 = i;
      } else {
        b1 = i;
      }
    }
    if (S[i] == 'R') {
      if (r1 != -1) {
        r2 = i;
      } else {
        r1 = i;
      }
    }
    if (S[i] == 'K') {
      k = i;
    }
  }
  if (b1%2 == b2%2) {
    flag = false;
  }
  if (!(r1 < k && k < r2)) {
    flag = false;
  }
  printyesno(flag);
  return 0;
}
