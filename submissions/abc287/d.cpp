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


int main() {
  string S,T;
  cin >> S >> T;
  int s = S.size(), t = T.size();
  vector<bool> former(t+1, false), latter(t+1, false);
  former[0] = true;
  latter[t] = true;
  bool tmp = true;
  rep(i,t) {
    if (!(S[i] == T[i] || S[i] == '?' || T[i] == '?'))
      tmp = false;
    former[i+1] = tmp;
  }
  tmp = true;
  rep(i,t) {
    if (!(S[s-1-i] == T[t-1-i] || S[s-1-i] == '?' || T[t-1-i] == '?'))
      tmp = false;
    latter[t-1-i] = tmp;
  }
  rep(i,t+1) {
    print((former[i] && latter[i] ? Yes : No));
  }
  return 0;
}
