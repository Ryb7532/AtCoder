#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define rrep(i,n) for (int i=(int)(n)-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int N;
  string S;
  cin >> N >> S;
  int res = -1;
  int l = 0;
  rep(i,N) {
    if (S[i] == '-') {
      res = max(res, l);
      l = 0;
    } else {
      l++;
    }
  }
  if (l != N)
    res = max(res, l);
  if (res == 0)
    res = -1;
  print(res);
  return 0;
}
