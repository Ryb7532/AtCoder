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
  int N;
  cin >> N;
  vector<string> s(N), t(N);
  rep(i,N) {
    cin >> s[i] >> t[i];
  }
  bool flag = true;
  rep(i,N) {
    bool first = false;
    bool last = false;
    rep(j,N) {
      if (i == j)
        continue;
      if (s[i] == s[j] || s[i] == t[j])
        first = true;
    }
    rep(j,N) {
      if (i == j)
        continue;
      if (t[i] == s[j] || t[i] == t[j])
        last = true;
    }
    if (first && last)
      flag = false;
  }
  print((flag ? Yes : No));
  return 0;
}
