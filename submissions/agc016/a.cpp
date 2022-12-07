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
  int res = 100;
  rep(i,26) {
    vector<bool> change(N,false);
    bool flag = false;
    rep(j,N) {
      if (S[j] == 'a'+i) {
        flag = true;
        change[j] = true;
      }
    }
    if (!flag)
      continue;
    rep(j,N) {
      flag = true;
      rep(k,N-j) {
        flag &= change[k];
      }
      if (flag) {
        res = min(res, j);
        break;
      }
      rep(k,N-j-1) {
        change[k] = change[k] | change[k+1];
      }
    }
  }
  print(res);
  return 0;
}
