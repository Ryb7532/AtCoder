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
#define printYorN(f) cout << (f ? Yes : No) << endl


int main() {
  string S;
  cin >> S;
  bool flag = true;
  if (S.size() != 8) {
    printYorN(false);
    return 0;
  }
  if (!(S[0] >= 'A' && S[0] <= 'Z'))
    flag = false;
  if (!(S[1] >= '1' && S[1] <= '9'))
    flag = false;
  rep(i,5) {
    if (!(S[2+i] >= '0' && S[2+i] <= '9'))
      flag = false;
  }
  if (!(S[7] >= 'A' && S[7] <= 'Z'))
    flag = false;
  printYorN(flag);
  return 0;
}
