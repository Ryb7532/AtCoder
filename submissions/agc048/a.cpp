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
  int T;
  cin >> T;
  rep(_,T) {
    string S;
    cin >> S;
    int N = S.size();
    int res=-1;
    if (S>"atcoder") {
      print(0);
      continue;
    }
    rep(i,N-1) {
      if (S[i+1]!='a') {
        if (S[i+1]<='t')
          res = i+1;
        else
          res = i;
        break;
      }
    }
    print(res);
  }
  return 0;
}
