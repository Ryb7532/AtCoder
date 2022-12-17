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
  bool flag = true;
  vector<bool> lowcase(26, false), capital(26, false);
  for (char c : S) {
    if (0 <= c-'a' && c-'a' < 26) {
      if (lowcase[c-'a'])
        flag = false;
      lowcase[c-'a'] = true;
    } else {
      if (capital[c-'A'])
        flag = false;
      capital[c-'A'] = true;
    }
  }
  bool used_lowcase = false, used_capital = false;
  rep(i,26) {
    used_lowcase = used_lowcase || lowcase[i];
    used_capital = used_capital || capital[i];
  }
  if (!used_capital || !used_lowcase)
    flag = false;
  print((flag ? Yes : No));
  return 0;
}
