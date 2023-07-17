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
  int H,W;
  cin >> H >> W;
  vector<string> S(W),T(W);
  rep(i,H) {
    string s;
    cin >> s;
    rep(j,W)
      S[j].push_back(s[j]);
  }
  rep(i,H) {
    string t;
    cin >> t;
    rep(j,W)
      T[j].push_back(t[j]);
  }
  sort(all(S));
  sort(all(T));
  bool flag = true;
  rep(i,W) {
    if (S[i] != T[i])
      flag = false;
  }
  printYorN(flag);
  return 0;
}
